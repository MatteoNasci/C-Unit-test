#rm -rf build
mkdir build
cd build
cmake ../
cmake --build . --target ALL_BUILD --config Release
cmake --build . --target ALL_BUILD --config Debug