#include "encryptor.cpp"
string n;
int choice;

void leer(){
    File f = File(n);
    cout<<"Que Quieres hacer?"<<endl
    <<"1)Leer"<<endl
    <<"2)Escribir"<<endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout<<endl<<f.read_file();
        break;
    
    case 2:
        string str, aux;
        cout<<"Que quieres escribir?"<<endl;
        while(1){
            cin >> aux;
            if(aux==".") break;
            str += aux + "\n";
        }
        f.write_file(str);
        break;
    }
}

void encriptar(){
    Encryptor e = Encryptor(n);
}

int main(){
    cout<<"Nombre del Archivo: ";
    cin >> n;
    do{
        cout<<"Opciones:"<<endl<<"1)Leer/Escribir"<<endl<<
        "2)Encriptar/desencriptar"<<endl<<
        "0)Terminar"<<endl;
        cout<<"Eleccion: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            leer();
            break;
        
        case 2:
            encriptar();
            break;
        }
    }while(choice!=0);
}