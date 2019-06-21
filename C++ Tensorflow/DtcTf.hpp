#pragma once

#include "tf_utils.hpp"
#include <iostream>

typedef struct {
    const char * name;
    int index;
} DTC_Tensor_Name;

class TfWrapper {
private:
    TF_Graph *graph = nullptr;
    TF_Session *session = nullptr; 
    std::vector<TF_Output> input_ops;
    std::vector<TF_Tensor*> input_tensors;
    std::vector<TF_Output> output_ops;
    std::vector<TF_Tensor*> output_tensors;

public:
    bool isGraphOK(void);

    bool setInputOutput(std::vector<DTC_Tensor_Name> inputNodesNames, std::vector<std::vector<std::int64_t> > inputNodesDims,
                        std::vector<DTC_Tensor_Name> outputNodesNames);
    
    bool setInputData(std::vector<std::vector<float>> inputNodesData);

    std::vector<std::vector<float>> getOutputData(void);

    bool runModel(void);

public:
    explicit TfWrapper(const char* graphPath);
    ~TfWrapper();
};
