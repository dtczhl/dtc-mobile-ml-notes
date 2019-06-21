To run C++ in Unity, create DLL plugins

### Configuration

1.  create **DLL** **empty** project using Visual Studio.

    C++ source template
    ```c
      #include "TestDLLSort.h"
      #include <algorithm>

      extern "C" {
  	    void TestSort(int a[], int length) {
  		    std::sort(a, a+length);
  	    }
      }
    ```
    C++ header template
    ```c
      #pragma once

      #define TESTDLLSORT_API __declspec(dllexport)

      extern "C" {
  	    TESTDLLSORT_API void TestSort(int a[], int length);
      }
    ```

2.  include headers and libs of packages by specifying `Project -> Properties -> C/C++/General/Additional Include Directories`, `Linker -> General -> Additional Library Directories` and `Linker -> Input -> Additional Dependencies`

3.  ensure x64

### Reference
*   How to integrate Point Cloud Library With Unity Google tango project?. <https://stackoverflow.com/questions/46299351/how-to-integrate-point-cloud-library-with-unity-google-tango-project>   
*   How to Write Native Plugins for Unity. <http://www.alanzucconi.com/2015/10/11/how-to-write-native-plugins-for-unity/>
*   Setting up Point Cloud Library with Visual Studio. <https://stackoverflow.com/questions/16514762/setting-up-point-cloud-library-with-visual-studio/20837645#20837645>
