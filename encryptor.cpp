#include "encryptor.h"

Encryptor::Encryptor(string name): File(name){
    if(!has_seed()){
        srand(time(0));
        seed = (rand() % (SEED_MAX - SEED_MIN + 1)) + SEED_MIN;
        back_up_seed();
    }else
        seed = read_seed();
}

Encryptor::Encryptor(string name, int s): File(name){
    if(!has_seed()){
        this->seed=s;
        back_up_seed();
    }else
        seed = read_seed();
}

int Encryptor::encrypt(){
    string aux = read_file();
    if(!last_operation_correct())   return -1;
    for(int i=0; i<aux.length(); i++){
        aux[i]+=seed;
    }
    overwrite_file(aux);
    if(!last_operation_correct())   return -1;
    return 0;
}

int Encryptor::decrypt(){
    string aux = read_file();
    if(!last_operation_correct())   return -1;
    for(int i=0; i<aux.length(); i++){
        aux[i]-=seed;
    }
    overwrite_file(aux);
    if(!last_operation_correct())   return -1;
    return 0;
}

//Métodos privados
void Encryptor::back_up_seed(){
    File aux = File(get_file_name()+".key");
    aux.overwrite_file(to_string(seed));
}

bool Encryptor::has_seed(){
    return File::exists(get_file_name()+".key");
}

int Encryptor::read_seed(){
    File aux = File(get_file_name()+".key");
    return stoi(aux.read_file());
}