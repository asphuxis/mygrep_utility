# mygrep_utility
This repo includes project files for a clone of the linux GREP-tool done as part of a school project

**REPOSITORY CONTENTS**

This repository includes the following files :
- .gitignore - used the ignore unwanted files in local repository
- readme.md - this file
- man_grep_plain_ascii.txt - sample file
- mygrep-diagram.png - diagram for how the program functions
- mygrep.cpp - source code

**COMPILE AND RUN**

1. Clone repository or download the program files
2. Navigate to directory through terminal and compile with your preferred compiler
  -> Example with g++ : g++ -Werror -Wall -g -std=c++20 mygrep.cpp -o mygrep.exe
3. run program through terminal
  -> Read "**USAGE**" section of this readme to understand logic

**USAGE**

The program can be run in two different ways : 
1. User runs the program without arguments
  -> Program asks the user for the string from which to search from and then the pattern which to search with
2. User runs the program with two arguments which specify pattern to search with and the file to search from
  -> Program uses the two arguments given when running the command and outputs the lines from the file matching the pattern
