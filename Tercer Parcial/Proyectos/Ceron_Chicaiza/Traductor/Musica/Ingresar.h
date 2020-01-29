/*******************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Alex Chicaiza
 *	Maria Belen Ceron
 *	NRC: 2967
 *	Fecha creacion: 19/01/2020
 *	Fecha ultima modificacion:	26/01/2020
 *	Docente: Ing. Fernando Solis
******************************************************************/

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;

class Ingreso{
public:
    int ingresarEnteros(char *);
    char *ingresarEnterosChar(char *);
    string ingresarLetras(string);

};
/**
    @brief ingresarEnteros
    @param *msg
    @return numero
*/
int Ingreso :: ingresarEnteros(char *msg){
    bool bandera=true;
	char caracter[]="";
	int contMenos=0;
	int i=0;
	int numero=0;
    printf("\n%s",msg);

	do{
	    caracter[0]=_getch();

        if((caracter[0]>=48 && caracter[0]<=57)){
                printf("%c",caracter[0]);
                numero=numero*10+atoi(caracter);
                i++;
            }else{
                if(caracter[0]==13){
                    bandera=false;
                }else{
                    if(caracter[0]==8 && i>0){
                        printf("\b \b");
                        i--;
                        numero=numero/10;
                        if(i==0){
                            contMenos=0;
                            numero=0;
                        }
                    }
                }
            }
        }while(bandera);
        if(contMenos>0)
            numero=numero*(-1);
        return numero;
}

/**
    @brief ingresarLetras
    @param *msg
    @return palabra
*/
string Ingreso ::ingresarLetras(string msg){
	
	cout << "\n\t" << msg;

	bool flag = true;
	char caracter[] = "";
	string lectura="";
	int i = 0;

	while (flag) {

		caracter[0] = _getch();

		if ((caracter[0] >= 65 && caracter[0] <= 90) || (caracter[0] >= 97 && caracter[0] <= 122) || caracter[0] == 32)
		{
			std::cout << caracter[0];
			lectura+= caracter[0];
			i++;
		}
		else
		{
			if (caracter[0] == 13)
			{
				flag = false;
			}
			else
			{
				if (caracter[0] == 8 && i > 0)
				{
					lectura = lectura.substr(0,lectura.length()-1);
					std::cout << "\b \b";
					i--;
				}
			}
		}
	}
	//*(lectura + i) = '\0';
	return lectura;
}

char * Ingreso :: ingresarEnterosChar(char *msg){
    bool bandera=true;
	char caracter[]="";
	int contMenos=0;
	int i=0;
	int numero=0;
    printf("\n%s\n",msg);

	do{
	    caracter[0]=_getch();

        if((caracter[0]>=48 && caracter[0]<=57)){
                printf("%c",caracter[0]);
                numero=numero*10+atoi(caracter);
                i++;
            }else{
                if(caracter[0]==13){
                    bandera=false;
                }else{
                    if(caracter[0]==8 && i>0){
                        printf("\b \b");
                        i--;
                        numero=numero/10;
                        if(i==0){
                            contMenos=0;
                            numero=0;
                        }
                    }
                }
            }
        }while(bandera);
        if(contMenos>0)
            numero=numero*(-1);

        char* cad = new char;
        sprintf(cad,"%i",numero);
        return cad;
}
