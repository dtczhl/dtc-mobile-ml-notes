
### Build PCL for android

Package versisons:
*  PCL  1.8.0
*  EIGEN  3.2.9
*  FLANN  1.8.4
*  BOOST  1.61.0


1.  install requirements
    ```
        apt-get install git make cmake
    ```

2.  download, unzip and export android ndk 14b
    ```
        wget https://dl.google.com/android/repository/android-ndk-r14b-linux-x86_64.zip
        export ANDROID_NDK=PATH_TO_YOUR_LOCAL_ANDROID_NDK_FOLDER
    ```

3. clone my forked repo, download packages and build
    ```
        git clone https://github.com/dtczhl/pcl-for-android.git .
        ./download-setup.sh
        ./pcl-build-for-android.sh
    ```

### Android Studio config

1.  config `build.gradle` to use `armeabi-v7a` only
    ```
        ndk {
            abiFilters 'armeabi-v7a'
        }
    ```

2.  edit `local.properties` to use an old NDK that supports GCC (e.g., r17c). Edit `build.gradle` to use GCC
    ```
        cmake {
            // cppFlags ""
            arguments '-DANDROID_TOOLCHAIN=gcc',
                    '-DANDROID_STL=gnustl_static'
        }
    ```

3.  create `pcl` folder with `include` and `lib` subfolder, and copy compiled header folders `boost`, `flann` and `pcl` to `include`, and copy all `.a` files to `lib`. Move `pcl` folder to `src/main/cpp`

4.  under `src/main` folder, create `jniLibs/armeabi-v7a` folder and copy all `.so` files

5.  download `Eigen` library and rename to `Eigen` and put it in `src/main/cpp`

6.  edit `CMakeLists.txt`. A template is given (as well as a script to generate library info)

### Test

A simple codelet to test whether PCL is correctly configured.
```
  #include <pcl/point_types.h>
  #include <pcl/point_cloud.h>
  #include <pcl/io/pcd_io.h>

  ......
  pcl::PointCloud<pcl::PointXYZ> cloud;
  cloud.width = 2048;
  cloud.height = 1;
  cloud.is_dense = true;

  for (int i = 0; i < cloud.width; i++) {
      cloud.push_back(pcl::PointXYZ(i, i, i));
  }
```

### Reference
<https://blog.csdn.net/hehehetanchaow/article/details/81033791>
