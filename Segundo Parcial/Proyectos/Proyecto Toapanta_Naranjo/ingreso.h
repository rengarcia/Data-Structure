#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Ingreso{
public:
    float ingresarFloat(char*);
    bool validarFloat(string);
    int ingresarInt(char*);
    bool validarInt(string);
    string ingresarString(char*);
    bool validarString(string);
    string ingresar10Digitos(char*);
    bool validar10Digitos(string);

};

float Ingreso::ingresarFloat(char* msg){
    string flotante;
    bool flag;
    do{
        try{
            cout<<msg;
            getline(cin,flotante);
            flag = validarFloat(flotante);
            if(flag){
                throw flotante;
            }
        }catch(string e){
            cout<<"Dato invalido "<<e<<endl;
        }
    }while(flag);

    return atof(flotante.c_str());
}

bool Ingreso::validarFloat(string valor){
    bool flag;
    for(int i = 0; i<valor.length(); i++){
        if(isdigit(valor[i])){
           flag = false;
        }else{
            if(valor[i]== '.'){
                flag = false;
            }else{
                flag = true;
                break;
            }
        }
    }
    return flag;
}


int Ingreso::ingresarInt(char* msg){
    string numero;
    bool flag;
    do{
        try{
            cout<<msg;
            getline(cin,numero);
            flag = validarInt(numero);
            if(flag){
                throw numero;
            }
        }catch(string e){
            cout<<"Dato invalido "<<e<<endl;
        }
    }while(flag);

    return atoi(numero.c_str());
}

bool Ingreso::validarInt(string valor){
    bool flag;
    for(int i = 0; i<valor.length(); i++){
        if(isdigit(valor[i])){
           flag = false;
        }else{
            return true;
        }
    }
    return flag;
}

string Ingreso::ingresarString(char* msg){
    string dato;
    bool flag;
    do{
        try{
            cout<<msg;
            getline(cin,dato);
            flag = validarString(dato);
            if(flag){
                throw dato;
            }
        }catch(string e){
            cout<<"Dato invalido "<<e<<endl;
        }
    }while(flag);
    return dato;
}

bool Ingreso::validarString(string valor){
    bool flag;
    for(int i = 0; i<valor.length(); i++){
        if(isalpha(valor[i]) || valor[i] == ' '){
           flag = false;
        }else{
            return true;
        }
    }
    return flag;
}

string Ingreso::ingresar10Digitos(char* msg){
    string dato;
    bool flag;
    do{
        try{
            cout<<msg;
            getline(cin,dato);
            flag = validar10Digitos(dato);
            if(flag){
                throw dato;
            }
        }catch(string e){
            cout<<"Dato invalido "<<e<<endl;
        }
    }while(flag);
    return dato;
}

bool Ingreso::validar10Digitos(string valor){
    bool flag;
    int cont = 0;
    for(int i = 0; i<valor.length(); i++){
        if(isdigit(valor[i])){
            cont++;
           if(cont == 10){
            flag = false;
           }else{
            flag = true;
           }
        }else{
            return true;
        }
    }
    return flag;
}


