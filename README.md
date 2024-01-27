# Skip
Skip > Skype

# Build Project

```
conan install . -of build
cmake -B build -DCMAKE_TOOLCHAIN_FILE=./build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
