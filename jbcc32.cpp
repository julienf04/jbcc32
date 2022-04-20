// This program makes it easy to compile c++ code using Borland 5.5
// Created by Julian Fajardo
// Last update: 19/4/2022 (dd/mm/aaaa)

// For any bug, doubt, comment or anything, you can contact me on:
//  -Gmail: julian.fajardo000@gmail.com
//  -Instagram: julienf_04;

// REQUERIMENTS TO USE THIS PROGRAM:
//  1) You need to have installed Borland 5.5 compiler
//  2) You need to add 'C:\Borland\BCC55\bin' folder (or wherever you have the compiler) to 'Environment Variables -> Path'
//  3) You need to add 'C:\Program Files\JuliFajardo\jbcc32' folder (or wherever you have jbcc32) to 'Environment Variables -> Path'
//  4) The terminal needs to be in the path where the file you want to compile is

// ALL jbcc32 COMMANDS:
//  'jbcc32 help': Shows info about jbcc32"
//  'jbcc32': Compiles all .cpp files found in the current path, and produces 'Program.exe' file in \obj folder
//  'jbcc32 [filename]': Compiles all .cpp files found in current path, and produces '[filename].exe' file in \obj folder

// Compilation example: I need to compile a .cpp file that is located in the path 'C:\users\SomeFolder\AnotherFolder\Here is the file'
//  -Step 1: I go to the path where .cpp file is, using this command:
//      cd C:\users\SomeFolder\AnotherFolder\Here is the file
//  -Step 2: I compile that .cpp file, using this command:
//      jbcc32
//  Nice! Now my Program.exe is located in C:\users\SomeFolder\AnotherFolder\Here is the file\obj\'




#include <iostream>
#include <direct.h>
#include <filesystem>

using namespace std;
using namespace std::filesystem;


const string GMAIL = "julian.fajardo000@gmail.com";
const string INSTAGRAM = "julienf_04";
const string SOURCE_CODE = "https://github.com/julienf04/jbcc32.git";

const string CPP_EXTENSION = ".cpp";
const string H_EXTENSION = ".h";
const string LIB_EXTENSION = ".lib";
const string OBJ_PATH = "obj";

string headerIncludes = "";
string libs = "";
string cppFiles = "";

bool objPathExists = false;


void SetIncludeFolder(string folder)
{
    // In Borland 5.5, the command to include headers paths is "-I"
    headerIncludes += (" -I\"" + folder + "\"");
}

void SetLibFile(string lib)
{
    // In Borland 5.5, the command to include library files is "-L"
    libs += (" -L\"" + lib + "\"");
}

void SetCppFile(string cppFile)
{
    // In Borland 5.5, It is just necessary to write the name of file
    cppFiles += (" \"" + cppFile + "\"");
}


void WriteBCC32Parameters(string path = "./")
{
    bool alreadyIncluded = false;

    for (const directory_entry &file : directory_iterator(path))
    {
        path = file.path().generic_string();
        path = path.substr(2, path.length());

        if (file.is_directory())
        {
            if (path == OBJ_PATH)
                objPathExists = true;

            WriteBCC32Parameters(file.path().generic_string());
        }
        else
        {
            string extensionFile = file.path().extension().generic_string();

            if (extensionFile == H_EXTENSION && !alreadyIncluded)
            {
                string parentPath = file.path().parent_path().generic_string();
                SetIncludeFolder(parentPath);
                alreadyIncluded = true;
            }

            else if (extensionFile == LIB_EXTENSION)
                SetLibFile(path);

            else if (extensionFile == CPP_EXTENSION)
                SetCppFile(path);
        }
    }
}

string FilenameWithoutExtension(string filename)
{
    int position = filename.find_last_of(".");
    string filenameWithoutExtension = filename.substr(0, position);
    return filenameWithoutExtension;
}

void SettingObjFolder()
{
    if (!objPathExists)
        create_directory(OBJ_PATH);
}

void Compile(string command)
{
    const char* lpCommand = command.c_str();
    system(lpCommand);
}

string ExecutableFilename(int argc, char* argv[])
{
    // In Borland 5.5, the command to set the name of the .exe file is "-e"
    string exeFilename;

    if (argc >= 2)
        exeFilename = " -e\"" + string(argv[1]) + "\"";
    else
        exeFilename = " -e\"Program\"";

    return exeFilename;
}

void HelpCommand()
{
    cout << endl;
    cout << "This program makes it easy to compile C++ code using Borland 5.5!" << endl;
    cout << "Created by Julian Fajardo" << endl << endl;

    cout << "For any bug, doubt, comment or anything, you can contact me on:" << endl;
    cout << "-Gmail: " << GMAIL << endl;
    cout << "-Instagram: " << INSTAGRAM << endl;
    cout << "Source code: " << SOURCE_CODE << endl << endl;

    cout << "REQUERIMENTS TO USE THIS PROGRAM:" << endl;
    cout << "\t1) You need to have installed Borland 5.5 compiler" << endl;
    cout << "\t2) You need to add 'C:\\Borland\\BCC55\\bin' folder (or wherever you have the compiler) to 'Environment Variables -> Path'" << endl;
    cout << "\t3) You need to add 'C:\\Program Files\\JuliFajardo\\jbcc32' folder (or wherever you have jbcc32) to 'Environment Variables -> Path'" << endl;
    cout << "\t4) The terminal needs to be in the path where the file you want to compile is" << endl << endl;

    cout << "ALL jbcc32 COMMANDS:" << endl;
    cout << "\t-'jbcc32 help': Shows info about jbcc32" << endl;
    cout << "\t-'jbcc32': Compiles all .cpp files found in the current path, and produces 'Program.exe' file in \\obj folder" << endl;
    cout << "\t-'jbcc32 [filename]': Compiles all .cpp files found in current path, and produces '[filename].exe' file in \\obj folder" << endl << endl;

    cout << "Compilation example: I need to compile a .cpp file that is located in the path 'C:\\users\\SomeFolder\\AnotherFolder\\Here is the file'" << endl;
    cout << "-Step 1: I go to the path where .cpp file is, using this command:" << endl;
    cout << "\tcd C:\\users\\SomeFolder\\AnotherFolder\\Here is the file" << endl;
    cout << "-Step 2: I compile that .cpp file, using this command:" << endl;
    cout << "\tjbcc32" << endl;
    cout << "Nice! Now my Program.exe is located in C:\\users\\SomeFolder\\AnotherFolder\\Here is the file\\obj\\'" << endl;
}

string ToLowerCase(string toConvert)
{
    transform(toConvert.begin(), toConvert.end(), toConvert.begin(), ::tolower);
    return toConvert;
}

int main(int argc, char* argv[])
{
    if (argc >= 2 && ToLowerCase(string(argv[1])) == "help")
    {
        HelpCommand();
    }
    else
    {
        cout << endl;
        cout << "If you need help about this jbcc32 program, use this command: 'jbcc32 help'" << endl << endl;


        cout << "Find files..." << endl;
        WriteBCC32Parameters();

        SettingObjFolder();

        // In Borland 5.5, the command to places compilation files in specified path is "-n"
        string objPathCommand = (" -n\"" + OBJ_PATH + "\"");
        string exeFileName = ExecutableFilename(argc, argv);
        string BorlandCommand = "bcc32";

        string command = BorlandCommand + headerIncludes + libs + objPathCommand + exeFileName + cppFiles;

        cout << "Command used to compile: " << command << endl;
        cout << "Compiling..." << endl;

        Compile(command);    
    }

    return 0;
}