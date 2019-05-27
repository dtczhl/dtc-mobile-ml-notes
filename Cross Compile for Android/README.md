Build android programs and shared libraries

### Configurations

1. Create standalone android develop environment with android NDK
    ```
    /bin/bash android-ndk-path/build/tools/make-stanalone-toolchain.sh --arch=arm64 --install-dir=INSTALL_DIR
    ```
    `arm` for 32 bit and `arm64` for 64 bit. Python version: `make_standalone_toolchain.py` under same directory

1. set `CC` and `CXX`
    ```
    export CC=INSTALL_DIR/bin/aarch64-linux-android-gcc
    export CXX=INSTALL_DIR/bin/aarch64-linux-android-g++
    ```

### Test

1. make a hello_world.cpp program

2. compile

    ```
    $CC -pie hello_world.cpp
    ```

3. push `a.out` to android phone, and run it
    ```
    adb push a.out /data/local/tmp/.
    adb shell "./data/local/tmp/a.out"
    ```




### Reference
* Cross Compiling C/C++ for Android. http://nickdesaulniers.github.io/blog/2016/07/01/android-cli/
