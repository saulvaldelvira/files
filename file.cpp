#pragma once
#include "file.h"

File::File(string name){
    filename = name;
    last_operation_status = CORRECT;
}

string File::get_file_name(){
    return filename;
}

string File::read_file(){
    string result = "";
    file.open(filename, ios::in);
    if(file.is_open()){
        last_operation_status = CORRECT;
        string str;
        while (1) {
            getline(file, str);
            result += str + "\n";
            if (file.eof()) break;
        }
    }else   error();
    file.close();
    return result;
}

void File::write_file(string msg){
    file.open(filename, ios::app);
    if(file.is_open()){
        last_operation_status = CORRECT;
        file << msg + "\n";
    }
    else    error();
    file.close();
}

void File::overwrite_file(string msg){
    file.open(filename, ios::out);
    if(file.is_open()){
        last_operation_status = CORRECT;
        file << msg + "\n";
    }
    else    error();
    file.close();
}

bool File::exists(){
    bool result;
    file.open(filename, ios::in);
    result = file.is_open();
    file.close();
    return result;
}

bool File::exists(string n){
    fstream f;
    bool result;
    f.open(n, ios::in);
    result = f.is_open();
    f.close();
    return result;
}

bool File::last_operation_correct(){
    return last_operation_status==CORRECT;
}

//Métodos Privados
void File::error(){
    last_operation_status = INCORRECT;
    cout<<"Ha habido un problema al procesar el archivo: "<<filename<<endl;
}