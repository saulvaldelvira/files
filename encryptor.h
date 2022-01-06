#pragma once
#include "file.cpp"
using std::to_string;
#include <time.h>

class Encryptor: public File{
private:
    //Constantes
    const static int SEED_MAX = 100;
    const static int SEED_MIN = 5;
    //Variables
    int seed;
    //Métodos
    void back_up_seed();
    bool has_seed();
    int read_seed();
public:
    Encryptor(string name);
    Encryptor(string name, int s);
    int encrypt();
    int decrypt();
};