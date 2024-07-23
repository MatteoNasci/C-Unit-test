#rm -rf build
mkdir build
cd build
cmake ../
cmake --build . --target ALL_BUILD --config Release
cmake --build . --target ALL_BUILD --config Debug
cmake --build . --target ALL_BUILD --config MinSizeRel
cmake --build . --target ALL_BUILD --config RelWithDebInfo