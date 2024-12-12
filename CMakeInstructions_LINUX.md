The following instructions will help you install CMake and use it to create executable files by compiling C++ code you write. These instructions are particularly relevant for developers using a Linux operating system.

## CMake Installation
On Arch Linux, installing CMake can be accomplished by using the following command:

sudo pacman -S cmake

## Steps to creating an Executable C++ File Using CMake
The following steps will help you compile and run an executable C++ file using CMake.

1. Create a CMakeLists.txt File  
This file contains the necessary information for CMake to compile the program and create an executable.

Specify the CMake Version by adding the following line to your CMakeLists.txt file to specify the CMake version you are using:
```
cmake_minimum_required(VERSION 3.31.2)
```
In this example, the version is 3.31.2. Replace it with your version, which you can find by running this command in your terminal:
```
cmake --version
```

Specify the project name by adding the following line:
```
project(your_project_name)
```
Replace your_project_name with your actual project name.

Specify the C++ standard by adding the following lines to ensure CMake uses the correct C++ standard:
```
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
These lines should remain unchanged.

Specify the executable file parameters by adding this line to define the name of your executable file and the C++ file to compile:
```
add_executable(exe_file_name your_project.cpp)
```
Replace exe_file_name with the desired name for your executable file. Replace your_project.cpp with the name of your C++ source file.

2. Create a Build Path and Use CMake to Compile  
Now that you have created a CMakeLists.txt file, follow these steps to compile your C++ file and generate an executable:

Create a Build Path using the following commands to create a build directory and run CMake:
```
mkdir build
cd build
cmake ..
```
 
After the build process completes, an executable file named after the first parameter in add_executable() will be created. Run the executable using:
```
./exe_file_name
```
Replace exe_file_name with the name you specified earlier.

Note: You can verify the creation of the executable file by using the ls command to list the contents of your directory. The executable file should have the same name as the one specified in add_executable().

