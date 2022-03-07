ft_containers
=============
Objectives
----------
  - Implement vector, map and stack from the c++ standard library.
  - Implement a reusable, standalone red and black binary tree class.
  - Produce a robust tester to test the validity and compile speed of the implemented library compared to the sandard library

Motivations
-----------
  - A deeper learning of c++ and its standard library containers.
  - A deeper learning of templated classes and clean coding practices.
  - Learning how to implement red and black binary trees.
  - Complete the 42 school project.

Contents
--------
  1. ./includes/
    - .hpp files for including vector map and stack
    - .hpp that include the utilities necessary for the implemented containers
  2. ./srcs/
    - .cpp files for compiling the tester
  3. ./Makefile
    - ```make``` will compile the tests
    - ```make test``` will compile tests and compare to the standard library
   4. ./test.sh
    - script to test the compile speed
   5. ./.gitignore
   6. ./README.md
   7. ./en.subject.pdf
    - 42 school subject

Usage
-----
Validity Tester:

---
 - run ```Make test``` in root folder
 - If no differences are shown then the implemented containers behave as expected
Speed Tester:

---
  - run ```./test.sh``` in root folder
Adding your own tests:

---
  - go to srcs/<tested container>.cpp
  - create a container in the .cpp file by using ```LIB:<tested container```
  - Run the Validity Tester again
