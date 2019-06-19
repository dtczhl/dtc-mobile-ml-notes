Build libtensorflowLite.so

### Install

In Anaconda environment
  ```
    conda install python=3.6
    conda install bazel=0.20.0
    git clone https://github.com/tensorflow/tensorflow.git -b r1.13
  ```

Other packages:
* Android SDK: 29.0.0 (other version should also work)
* Android NDK: r18b (important)

### Configure

1. `vi WORKSAPCE` under `tensorflow` folder. Add the following to the end
  ```
    android_sdk_repository(
      name = "androidsdk",
      api_level = 29,
      build_tools_version = "29.0.0",
      path = "path to your sdk",
    )

    android_ndk_repository(
      name = "androidndk",
      path = "path to your ndk",
      api_level = 18
    )
  ```

2. run `./configure` and select defaults.

3. `vi tensorflow/lite/BUILD`, and add the following to the end
  ```
    cc_binary(
      name = "libtensorflowLite.so",
      linkopts=[
      "-shared",
      "-W1,-soname=libtensorflowLite.so",
    ],
      linkshared = 1,
      copts = tflite_copts(),
      deps = [
        ":framework",
        "//tensorflow/lite/kernels:builtin_ops",
      ],
    )
  ```

4. run the following command and the built `libtensorflowLite.so` is in `bazel-bin/tensorflow/lite`
  ```
    bazel build //tensorflow/lite:libtensorflowLite.so --crosstool_top=//external:android/crosstool --cpu=arm64-v8a --host_crosstool_top=@bazel_tools//tools/cpp:toolchain --cxxopt="-std=c++11"

  ```



### Reference
* Zimeng Lyu. Tensorflow Lite, Android NDK. https://zimenglyu.com/en/ml/android/tensorflow/2018/11/27/tflite-android-ndk-eng.html
