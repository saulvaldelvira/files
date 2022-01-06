#include "encryptor.cpp"
#include <string>
using std::string;

int main(){
    Encryptor e = Encryptor("prueba.txt");
    e.encrypt();
}