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
    
