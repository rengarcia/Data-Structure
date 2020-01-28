#include <iostream>
#include "Excluir.h"
#include <string>
using namespace std;

//Universidad de las Fuerzas Armdas
//Nombre: Kevin Zurita
//NRC: 2967
//Docente: Ing. Edgar Solis
//Fecha de creacion: 23/09/2019
//FecHa de ultima modificacion: 1/10/2019

class Ingreso{
    public:
    	string ingresarString(char* );
		int ingresar(char* );   	
		string ingresarStringN(char* );
		string ingresarCedula(char *);
		bool validadCedula(string);
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

string  Ingreso::ingresarCedula(char *msg){
        string valor;
        bool flag;
        Excluir comprobante;
        cout<<msg<<endl;
        do{
        	cin>>valor;
        	flag=comprobante.controlCedula(valor);
		}while(flag==false);
        return valor;
    	}
    	
bool Ingreso::validadCedula(string cedula){
	int mul1=0,mul2=0,res,cont=1,sum1=0,sum2=0,sum3=0,ult_n1,ult_n2;
    long int num,coc1,coc2;
        num=strtoul(cedula.c_str(),NULL,10);
        mul1=0; mul2=0; sum1=0; sum2=0; sum3=0; cont=1;
        while (num<0)
            {
            	return false;
            }
        ult_n1=num%10;
        coc1=num/10;
        num=coc1;
            do{
                do{
                    coc2=num/10;
                    res=num%10;
                    if (cont%2==0)
                        {
                        mul2=res*1;
                        if (mul2>=10)
                            mul2-=9;
                        sum2+=mul2;
                        }
                    else
                        {
                        mul1=res*2;
                        if (mul1>=10)
                            mul1-=9;
                        sum1+=mul1;
                        }
                    cont++;
                    num=coc2;
                }while (coc2 != 0);
                sum3=sum1+sum2;
                if ((sum3%10)!=0)
                {
                   ult_n2=sum3/10;
                   ult_n2++;
                   ult_n2*=10;
                   ult_n2-=sum3;
                }
                else
                    ult_n2-=ult_n2;
                if(ult_n2==ult_n1)
                while (ult_n2==ult_n1)
                {
                	return true;
                }
        }while (ult_n2==ult_n1);
        return false;
}
