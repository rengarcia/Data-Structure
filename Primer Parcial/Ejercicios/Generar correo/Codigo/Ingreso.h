/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include "Excluir.h"
#include <string>
using namespace std;

class Ingreso{
    public:
    	string ingresarString(char* );
		int ingresar(char* );   	
		string ingresarStringN(char* );
};
string  Ingreso::ingresarString(char *msg){
        string valor;
        bool flag;
        Excluir comprobante;
        cout<<msg<<endl;
        do{
        	cin>>valor;
        	flag=comprobante.controlS(valor);
		}while(flag==false);
        return valor;
    	}
    	
string  Ingreso::ingresarStringN(char *msg){
        string valor;
        bool flag;
        Excluir comprobante;
        cout<<msg<<endl;
        do{
        	cin>>valor;
        	flag=comprobante.controlSN(valor);
		}while(flag==false);
        return valor;
    	}
    	
int Ingreso::ingresar(char *msg){
        string valor;
        bool flag;
        Excluir comprobante;
        cout<<msg<<endl;
        do{
        	cin>>valor;
        	flag=comprobante.control(valor);
		}while(flag==false);
        int num;
		num = strtof((valor).c_str(),0);
        return num;
    	}
