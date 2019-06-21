Build libtensorflowLite.so

### Install Tools

In Anaconda environment
  ```
    conda install python=3.6
    conda install bazel=0.20.0
    git clone https://github.com/tensorflow/tensorflow.git -b r1.13
  ```

Other packages:
* Android SDK: 29.0.0
* Android NDK: r18b

### Build libtensorflowLite.so

1.  `vi WORKSAPCE` under `tensorflow` folder. Add the following to the end
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

2.  run `./configure` and select defaults.

3.  `vi tensorflow/lite/BUILD`, and add the following to the end
  ```
    cc_binary(
      name = "libtensorflowLite.so",
      linkopts=[
      "-shared",
      "-Wl,-soname=libtensorflowLite.so",
    ],
      linkshared = 1,
      copts = tflite_copts(),
      deps = [
        ":framework",
        "//tensorflow/lite/kernels:builtin_ops",
      ],
    )
  ```

4.  run the following command and the built `libtensorflowLite.so` is in `bazel-bin/tensorflow/lite`
  ```
    bazel build //tensorflow/lite:libtensorflowLite.so --crosstool_top=//external:android/crosstool --cpu=arm64-v8a --host_crosstool_top=@bazel_tools//tools/cpp:toolchain --cxxopt="-std=c++11"

  ```

### Add Dependence

1.  create folder `distribution` and will have the following structure
  ```
    distribution
      - lib
        -- arm64-v8a
      - include  
        -- flatbuffers
        -- tensorflow
  ```

2.  copy `libtensorflowLite.so` to `distribution/lib/arm64-v8a`. Download flatbuffers and copy the headers to `distribution/include`. Copy `tensorflow/tensorflow` to `distribution/include`
  ```
    git clone https://github.com/google/flatbuffers.git
  ```

### Android Studio Configuration

1.  create C++ project

2.  add headers and the library to CMakelists.txt. Only need to change the distribution_DIR. Here I move `distribution` folder to `app/src/main/cpp/`
  ```
    set(distribution_DIR ${CMAKE_SOURCE_DIR}/distribution)

    target_include_directories(native-lib PRIVATE ${distribution_DIR}/include)

    add_library(libtensorflowLite SHARED IMPORTED)
    set_target_properties(libtensorflowLite PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/lib/arm64-v8a/libtensorflowLite.so)

    target_link_libraries( # Specifies the target library.
    native-lib
    libtensorflowLite
    # Links the target library to the log library
    # included in the NDK.
    ${log-lib})
  ```

3.  create `jniLibs` under `app/src/main` and copy `arm64-v8a` folder.

4.  `adb push` your `.tflite` to phone
  ```
    adb push your_model.tflite /sdcard/MyData/
  ```

5.  enable Android write and read permissions. Edit `manifests/AndroidManifest.xml`
  ```
  <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
  <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
  ```
  Then in the `MainActivity.java`
  ```
    private static final String[] PermissionStrings = {
      Manifest.permission.WRITE_EXTERNAL_STORAGE,
      Manifest.permission.READ_EXTERNAL_STORAGE
    };
    ......
    ActivityCompat.requestPermissions(this, PermissionStrings, 1);

  ```

### Example TensorflowLite Program

```
  tflite::StderrReporter error_reporter;
  auto model = tflite::FlatBufferModel::BuildFromFile("/sdcard/MyData/your_model.tflite", &error_reporter);

  tflite::ops::builtin::BuiltinOpResolver resolver;
  std::unique_ptr<tflite::Interpreter> interpreter;
  tflite::InterpreterBuilder(*model, resolver)(&interpreter);

  interpreter->AllocateTensors();

  LOGD("TF Lite Inference Starts");

  float *input = interpreter->typed_input_tensor<float>(0);
  input[0] = 0;

  interpreter->Invoke();

  float *output = interpreter->typed_output_tensor<float>(0);
  LOGD("TF Lite Inference Ends");
```

### Reference
* Zimeng Lyu. Tensorflow Lite, Android NDK. https://zimenglyu.com/en/ml/android/tensorflow/2018/11/27/tflite-android-ndk-eng.html
