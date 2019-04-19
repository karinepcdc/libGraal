# libGraal
Graal — Generic Array Algorithms Library

Compiling

This project may be compiled with CMake. CMake is an open-source, cross-platform family of tools designed to build, test and package software. Basically, cmake reads a script (CMakeLists.txt) with meta-information on the project and creates a Makefile automatically, tailored to your system configuration. After that, you may run the make command, as usual.

Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.


Compiling the Library

To compile the library only we should follow these steps:

    mkdir build: this creates a new directory in which the compilation output will be stored, including the executable.
    cd build: just moves into the directory created in the step above.
    cmake -G "Unix Makefiles" ..: asks cmake to create the Makefile based on the script found in CMakeLists.txt, one level up.
    cmake --build .: triggers the compiling process.
    make install: copies the library to the lib directory.
    ./run_tests: run all lib tests
