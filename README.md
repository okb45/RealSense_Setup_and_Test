How to setup Realsense Library:
  Run these commands in your home directory:
  
    git clone https://github.com/Microsoft/vcpkg.git
     cd vcpkg
    ./bootstrap-vcpkg.sh (if running on Windows run the .bat)
    ./vcpkg integrate install
    ./vcpkg install realsense2

  If running on Windows and the ./vcpkg install realsense2 fails:
   
    Open (or download) the Visual Studio installer.
    Click Modify on the Visual Studio Community
    In Workloads
      Select Desktop development with C++
    In Individual components
      Select C++ ATL for latest v143 build tools (x86 & x64)
      Select C++ MFC for latest v143 build tools (x86 & x64)

  Clone the project and enter the MyRealsenseApp directory.
  Make sure CMAKE is installed on your machine

  
  If using Windows:
    Run these commands and edit the file path based on the path to vcpkg:
  
      cmake -B build -S. -DCMAKE_TOOLCHAIN_FILE=C:/path-to-vcpkg/scripts/buildsystems/vcpkg.cmake
      cmake --build build --config Release
  
  Now, to run the depth sense test, make sure the RealSense camera is connected to the machine and run:
  
      .\build\Release\MyRealsenseApp.exe
  
