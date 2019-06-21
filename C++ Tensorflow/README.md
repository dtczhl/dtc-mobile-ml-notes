Tensorflow for C++

### Setup

1.  install Tensorflow for C
<https://github.com/Neargye/tensorflow/releases>

2. a simple CMake template
  ```
    cmake_minimum_required (VERSION 2.6)
    project (mobileAR)

    include_directories(include /home/dtc/Software/Tensorflow/libtensorflow-cpu-linux-x86_64-1.13.1/include)
    link_directories(/home/dtc/Software/Tensorflow/libtensorflow-cpu-linux-x86_64-1.13.1/lib)

    file(GLOB SOURCES "src/*.cpp")

    add_executable(mobileAR ${SOURCES})
    target_link_libraries(mobileAR tensorflow)
  ```

3.  good tutorial examples on how to use it. Utility files: `tf_utils.hpp`, `tf_utils.cpp`
  ```
    https://github.com/Neargye/hello_tf_c_api
  ```

4.  I also write a simple wrapper, see `DtcTf.hpp`, `DtcTf.cpp`

5.  an example. `tfModelPath` is a `string` to the `.pb` file
   ```
    TfWrapper tfWrapper(tfModelPath.c_str());
    if (!tfWrapper.isGraphOK()) {
        std::cerr << "Error: load tensorflow graph fails" << std::endl;
        exit(1);
    }

    std::vector<DTC_Tensor_Name> inputNodeNames = {{"input_input", 0}};
    std::vector<std::vector<std::int64_t>> inputNodeDims = {{1, 100}};
    std::vector<DTC_Tensor_Name> outputNodeNames = {{"output/Sigmoid", 0}};

    if (!tfWrapper.setInputOutput(inputNodeNames, inputNodeDims, outputNodeNames)) {
        std::cerr << "Error: create tensorflow session fails" << std::endl;
        exit(1);
    }

    std::vector<float> input_vals;
    for (int i = 0; i < 100; i++) {
        input_vals.push_back(1);
    }
    std::vector<std::vector<float>> input_vals_array = {input_vals};
    if (!tfWrapper.setInputData(input_vals_array)) {
        std::cerr << "Error: set tensorflow input data fails" << std::endl;
        exit(1);
    }

    if (!tfWrapper.runModel()) {
        std::cerr << "Error: run tensorflow model fails" << std::endl;
        exit(1);
    }

    std::cout << "run model finished" << std::endl;

    std::vector<std::vector<float>> results = tfWrapper.getOutputData();

    std::cout << "Output value: " << results[0][0] << std::endl;
  ```
