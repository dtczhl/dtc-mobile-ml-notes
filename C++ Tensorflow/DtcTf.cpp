#include "DtcTf.hpp"
#include <cstdlib>
#include <cstring>

bool TfWrapper::isGraphOK(void) {
    return graph != nullptr;
}

bool TfWrapper::setInputOutput(
        std::vector<DTC_Tensor_Name> inputNodesNames, std::vector<std::vector<std::int64_t> > inputNodesDims,
        std::vector<DTC_Tensor_Name> outputNodesNames){
    
    if (inputNodesNames.size() != inputNodesDims.size()) {
        std::cerr << "Error: input nodes and dims mismatch!" << std::endl;
        return false;
    }

    for (DTC_Tensor_Name dtcInputTensor: inputNodesNames) {
        this->input_ops.push_back({TF_GraphOperationByName(this->graph, dtcInputTensor.name), dtcInputTensor.index});
    }

    for (std::vector<std::int64_t> dims: inputNodesDims) {
        std::size_t data_size = sizeof(float);
        for (auto i: dims) {
            data_size *= i;
        }
        TF_Tensor *tensor = TF_AllocateTensor(TF_FLOAT, dims.data(), static_cast<int>(dims.size()), data_size);
        if (tensor == nullptr || TF_TensorType(tensor) != TF_FLOAT || 
            TF_NumDims(tensor) != static_cast<int>(dims.size()) ||
            TF_TensorByteSize(tensor) != data_size) {
            std::cerr << "Error: create input tensor failed!" << std::endl;
            return false;
        }

        this->input_tensors.push_back(tensor);
    }

    for (DTC_Tensor_Name dtcOutputTensor: outputNodesNames) {
        this->output_ops.push_back({TF_GraphOperationByName(this->graph, dtcOutputTensor.name), dtcOutputTensor.index});
    }

    this->output_tensors = {nullptr};
    this->session = tf_utils::CreateSession(this->graph);

    return true;
}

bool TfWrapper::setInputData(std::vector<std::vector<float>> inputNodesData) {

    if (this->input_tensors.size() != inputNodesData.size()) {
        std::cerr << "Error: num of input data does not match num of input_tensors" << std::endl;
        return false;
    }

    for (int i = 0; i < this->input_tensors.size(); i++) {
        TF_Tensor *tensor = this->input_tensors[i];
        if (TF_TensorByteSize(tensor) != inputNodesData[i].size() * sizeof(float)) {
            std::cerr << "Error: tensor data size does not match" << std::endl;
            return false;
        }
        std::memcpy(TF_TensorData(tensor), inputNodesData[i].data(), TF_TensorByteSize(tensor));
    }

    return true;
}

std::vector<std::vector<float>> TfWrapper::getOutputData(void) {
    return tf_utils::TensorsData<float>(this->output_tensors);
}

bool TfWrapper::runModel(void) {
    TF_Code code = tf_utils::RunSession(this->session, 
            this->input_ops, this->input_tensors, this->output_ops, this->output_tensors);
    
    if (code != TF_OK) {
        std::cerr << "Error: run session fails. TF_Code: " << code << std::endl;
        return false;
    }

    return true;
}

TfWrapper::TfWrapper(const char* graphPath){

    std::cout << "Tensorflow version: " << TF_Version() << std::endl;

    this->graph = tf_utils::LoadGraph(graphPath);
    if (graph == nullptr) {
        std::cerr << "Error: cannot load tensorflow graph: " << graphPath << std::endl;
    }
}

TfWrapper::~TfWrapper() {
    tf_utils::DeleteTensors(this->input_tensors);
    tf_utils::DeleteTensors(this->output_tensors);
    tf_utils::DeleteGraph(this->graph);
}