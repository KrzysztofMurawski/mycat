# Overview
This is my implementation of "cat" command called "mycat" used to write contents of a file to console. 
It uses open(), read(), write(), close() system calls from the standard C library.

# Usage
`mycat [file1] [file2] ...`

# Installation

Requirements: 
- GCC
- CMake
  

`git clone https://github.com/KrzysztofMurawski/mycat.git`

`cd mycat`

`cmake -S . -B build/`

`cd build/`

`make`

`sudo cmake --install build`
