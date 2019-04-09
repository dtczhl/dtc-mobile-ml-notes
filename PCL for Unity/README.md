### Configuration

1. download PCL AllInOne

    https://github.com/PointCloudLibrary/pcl/releases

1. create **DLL** **empty** project using Visual Studio. 

    C++ source template
    ```
    #include "TestDLLSort.h"
    #include <algorithm>

    extern "C" {
	    void TestSort(int a[], int length) {
		    std::sort(a, a+length);
	    }
    }
    ```

    C++ header template
    ```
    #pragma once

    #define _SILENCE_FPOS_SEEKPOS_DEPRECATION_WARNING

    #define TESTDLLSORT_API __declspec(dllexport) 

    extern "C" {
	    TESTDLLSORT_API void TestSort(int a[], int length);
    }
    ```

1. disable warnings. `Project -> Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions` adds `_CRT_SECURE_NO_WARNINGS`

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

### Reference
* How to integrate Point Cloud Library With Unity Google tango project?. https://stackoverflow.com/questions/46299351/how-to-integrate-point-cloud-library-with-unity-google-tango-project   
* How to Write Native Plugins for Unity. http://www.alanzucconi.com/2015/10/11/how-to-write-native-plugins-for-unity/
* Setting up Point Cloud Library with Visual Studio. https://stackoverflow.com/questions/16514762/setting-up-point-cloud-library-with-visual-studio/20837645#20837645