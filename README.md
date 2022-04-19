# jbcc32
This is a program that makes it easy to compile C++ code using the Borland 5.5 compiler. This program must be executed on CMD

Created by Julian Fajardo
Last update: 19/4/2022 (dd/mm/aaaa)

For any bug, doubt, comment or anything, you can contact me on:
 -Gmail: julian.fajardo000@gmail.com
 -Instagram: julienf_04;

REQUERIMENTS TO USE THIS PROGRAM:
 1) You need to have installed Borland 5.5 compiler
 2) You need to add 'Borland\BCC55\bin' folder to 'Environment Variables -> Path'
 3) The terminal needs to be in the path where the file you want to compile is

ALL jbcc32 COMMANDS:
 'jbcc32 help': Shows info about jbcc32"
 'jbcc32': Compiles all .cpp files found in the current path, and produces 'Program.exe' file in \obj folder
 'jbcc32 [filename]': Compiles all .cpp files found in current path, and produces '[filename].exe' file in \obj folder

Compilation example: I need to compile a .cpp file that is located in the path 'C:\users\SomeFolder\AnotherFolder\Here is the file
 -Step 1: I go to the path where .cpp file is, using this command:
     cd C:\users\SomeFolder\AnotherFolder\Here is the file
 -Step 2: I compile that .cpp file, using this command:
     jbcc32
 Nice! Now my Program.exe is located in C:\users\SomeFolder\AnotherFolder\Here is the file\obj\'