#include "Palabra.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include "TraformacionString.h"

using namespace std;

void codificar(string &nombre,int i)
{
        do
        {
            if(i%2==0)
            {
                nombre.at(i)=(nombre.at(i)+6)+nombre.length();
            }
            else{
                nombre.at(i)=(nombre.at(i)+3)-nombre.length();
            }
            i++;
        }while(i!=nombre.length());

}
void decodificar(string &nombre,int i)
{
        do
        {
            if(i%2==0)
            {
                nombre.at(i)=(nombre.at(i)-6)-nombre.length();
            }
            else{
                nombre.at(i)=(nombre.at(i)-3)+nombre.length();
            }
            i++;
        }while(i!=nombre.length());

}
void write_file_E(Palabra p)
{
    ofstream archivo;
    archivo.open("Encriptado.txt",ios::out|ios::app);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
        archivo<<p.getEspanol()<<";"<<p.getIngles()<<";"<<p.getClave()<<";"<<p.getClaveE()<<endl;
    }

    archivo.close();
}
void write_file_D(Palabra p)
{
    ofstream archivo;
    archivo.open("DeseEncriptado.txt",ios::out|ios::app);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
        archivo<<p.getEspanol()<<";"<<p.getIngles()<<";"<<p.getClave()<<";"<<p.getClaveE()<<endl;
    }

    archivo.close();
}
void encriptar_Txt()
{
    ifstream archivo;
    string espanol,ingles,clave,claveE;
    archivo.open("Dic.txt",ios::in);
    if (archivo.fail())
    {
        cout<<"No se puedo acceder al archivo"<<endl;
    }
    else
    {
        while(!archivo.eof()){
            Palabra p;
            getline(archivo,espanol,';');
            getline(archivo,ingles,';');
            getline(archivo,clave,';');
            getline(archivo,claveE,'\n');
            codificar(claveE,0);
            codificar(espanol,0);
            codificar(clave,0);
            codificar(ingles,0);
            cout<<ingles<<endl;
            cout<<espanol<<endl;
            p.setEspanol(espanol);
            p.setIngles(ingles);
            p.setClave(stringAint(clave));
            p.setClaveE(stringAint(claveE));
            write_file_E(p);
        }
    }
    archivo.close();
}
void desenEncriptar_Txt()
{
    ifstream archivo;
    string espanol,ingles,clave,claveE;
    archivo.open("Encriptado.txt",ios::in);
    if (archivo.fail())
    {
        cout<<"No se puedo acceder al archivo"<<endl;
    }
    else
    {
        while(!archivo.eof()){
            Palabra p;
            getline(archivo,espanol,';');
            getline(archivo,ingles,';');
            getline(archivo,clave,';');
            getline(archivo,claveE,'\n');
            decodificar(claveE,0);
            decodificar(espanol,0);
            decodificar(clave,0);
            decodificar(ingles,0);
            cout<<ingles<<endl;
            cout<<espanol<<endl;
            p.setEspanol(espanol);
            p.setIngles(ingles);
            p.setClave(stringAint(clave));
            p.setClaveE(stringAint(claveE));
            write_file_D(p);
        }
    }
    archivo.close();
}

int main()
{
    encriptar_Txt();
    desenEncriptar_Txt();
    system("pause");
    return 0;
}
