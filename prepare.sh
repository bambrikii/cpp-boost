rm -rf CMakeFiles
rm -f CMakeCache.txt
rm -f cmake_install.cmake

# Install vcpkg
git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install boot
./vcpkg/vcpkg install fmt
./vcpkg/vcpkg integrate install

cmake CMakeLists.txt
