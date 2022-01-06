#pragma once
//Iostream
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//String
#include <string>
using std::string;
//File Stream
#include <fstream>
using std::fstream;
using std::ios;

class File{
private:
    //Constantes
    const static int CORRECT = 1;
    const static int INCORRECT = -1;
    //Variables
    fstream file;
    string filename;
    int last_operation_status;
    //Métodos
    void error();
public:
    File(string name);
    string get_file_name();
    string read_file();
    void write_file(string msg);
    void overwrite_file(string msg);
    bool exists();
    static bool exists(string n);
    bool last_operation_correct();
};