The following instructions will help you install CMake and use it to create executable files by compiling C++ code you write. These instructions will be particularly relevant for developers using a Linux operating system.

## CMake Installation
Using Arch Linux, installation of cmake can be accomplished by simply using the following command,
```
sudo pacman -S cmake
```
## Creating an executable C++ file using CMake
The following steps will help you compile and run an executable C++ file using CMake.

### Create a CMakeLists.txt file
This file will comprise of necessary information for cmake to compile the program and create an executable. 

To start, specify which version of CMake you are using by writing the following line into your CMakeLists.txt file.
```
cmake_minimum_required(VERSION 3.31.2)
```
In this example, my cmake's version was 3.31.2. Your cmake version information can be found by returning to your terminal from your text editor and running the command: cmake --version. 

1. Specify your project's name by writing the following line. 
```
project(your_project_name)
```
Replace your_project_name with your project's name. 

2. Specifythat you are using the C++ standard, you must write the following lines. 
```
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
Do not change these lines.

3. Specify parameters used for creating your executable file. 
```
add_executable(exe_file_name your_project.cpp) 
```
In this line, the first parameter, exe_file_name details what your desired name is for your project's executable file. The second parameter, your_project.cpp details which cpp file you desire to compile and create an executable file for. 

### Create a build path and use CMake to create the executable C++ file. 
Now that you have created a CMakeLists.txt file, you can use it to create the specified executable file by performing the following steps. 

1. Create a build path and build the project files in that build folder using cmake. 
```
mkdir build

cd build

cmake ..
```
2. Then, you will see a file by the name of your first parameter in add_executable(). Run this executable file to output your code. 
```
./exe_file_name
```
Note: You can check if the executable file has been created by using the ls command to show your directory's contents. There, you will see an executable file by the same name specified earlier. 

