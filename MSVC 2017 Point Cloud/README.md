Creating Visual Studio 2017 environments for point cloud development

Packages
* PCL 1.9.1 (All in One)
* Qt 

### Configuration

1. download PCL AllInOne

    https://github.com/PointCloudLibrary/pcl/releases

1. download Qt

    https://www.qt.io/download

1. `Project -> Propertites`: All Configurations, All Platforms. `C/C++ general -> Additional Include Directoreis' 

    ```
    D:\Software\PCL 1.9.1\3rdParty\VTK\include\vtk-8.1
    D:\Software\PCL 1.9.1\3rdParty\Qhull\include
    D:\Software\PCL 1.9.1\3rdParty\FLANN\include
    D:\Software\PCL 1.9.1\3rdParty\Eigen\eigen3
    D:\Software\PCL 1.9.1\3rdParty\Boost\include\boost-1_68
    D:\Software\PCL 1.9.1\3rdParty
    D:\Software\PCL 1.9.1\include\pcl-1.9
    C:\Program Files\OpenNI2\Include
    D:\Qt\5.12.2\msvc2017_64\include
    ```

1. `Linker -> General -> Additional Library Directories`

    ```
    D:\Software\PCL 1.9.1\3rdParty\VTK\lib
    D:\Software\PCL 1.9.1\3rdParty\Qhull\lib
    D:\Software\PCL 1.9.1\3rdParty\FLANN\lib
    D:\Software\PCL 1.9.1\3rdParty\Boost\lib
    D:\Software\PCL 1.9.1\lib
    C:\Program Files\OpenNI2\Lib
    ```

1. `Linker -> Input -> Additional Dependencies` (add libraries here, to be done...........)


Some Errors

1. disable warnings. `Project -> Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions` adds `_CRT_SECURE_NO_WARNINGS`

1. `the argument to a feature-test macro must be a simple identifer`

    ```
    #if defined(__has_cpp_attribute) changed to
    #if defined(__clang__) && defined(__has_cpp_attribute)
    ```
    See https://stackoverflow.com/questions/52636944/using-boostthread-with-cmake-in-ms-visual-studio-2017-results-in-two-compiler

1. `seekpos()` error. Add the following to the header

    ```
    #define _SILENCE_FPOS_SEEKPOS_DEPRECATION_WARNING
    ``` 

### Reference
* How to integrate Point Cloud Library With Unity Google tango project?. https://stackoverflow.com/questions/46299351/how-to-integrate-point-cloud-library-with-unity-google-tango-project   
* How to Write Native Plugins for Unity. http://www.alanzucconi.com/2015/10/11/how-to-write-native-plugins-for-unity/
* Setting up Point Cloud Library with Visual Studio. https://stackoverflow.com/questions/16514762/setting-up-point-cloud-library-with-visual-studio/20837645#20837645