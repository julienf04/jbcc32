# jbcc32

# Introduction
This is a program that makes it easy to compile C++ code using the Borland 5.5 compiler. This program must be executed on CMD.

# How to install jbcc32
To install this program:
- Download this jbcc32.zip: https://drive.google.com/file/d/19x3AHcFrwJAjTTPY4yMq0ssr-bLdr5xq/view?usp=sharing
- Unzip it
- Run setup.exe

# Requirements to use this program
1. You need to have installed Borland 5.5 compiler.
2. You need to add 'C:\Borland\BCC55\bin' folder (or wherever you have the compiler) to 'Environment Variables -> Path'.
3. You need to add 'C:\Program Files\JuliFajardo\jbcc32' folder (or wherever you have jbcc32) to 'Environment Variables -> Path'.
4. The terminal needs to be in the path where the file you want to compile is.

# All jbcc32 commands:
```bash
jbcc32 help  # Shows info about jbcc32.
jbcc32  # Compiles all .cpp files found in the current path, and produces 'Program.exe' file in \obj folder.
jbcc32 [filename]  # Compiles all .cpp files found in current path, and produces '[filename].exe' file in \obj folder.
```

# Example:
I need to compile a .cpp file that is located in the path 'C:\users\SomeFolder\AnotherFolder\Here is the file'.

1. I go to the path where .cpp file is, using command cd [path]
2. I compile that .cpp file, using command jbcc32

```bash
cd C:\users\SomeFolder\AnotherFolder\Here is the file.
jbcc32
```

Nice! Now my Program.exe is located in C:\users\SomeFolder\AnotherFolder\Here is the file\obj\'


# Contact me
For any bug, doubt, comment or anything, you can contact me on:
 - Gmail: julian.fajardo000@gmail.com
 - Instagram: [https://www.instagram.com/julienf_04/](https://www.instagram.com/julienf_04/ "https://www.instagram.com/julienf_04/")
