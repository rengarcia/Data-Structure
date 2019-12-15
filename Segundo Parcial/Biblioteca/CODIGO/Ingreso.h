/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include<stdio.h>

class Ingreso {

public:
	char * ingresoCadena(char *mensage);
	char* ingresoNumero(char *mensage);
	char * ingresoCorreo(char *mensage);
};

char * Ingreso::ingresoCadena(char * mensage) {
	printf("%s ",mensage);

	bool flag=true;
	char caracter[]="";
	char *lectura=(char*)malloc(sizeof(char));
	int i=0;

	while(flag){

		caracter[0]= getch();

		if((caracter[0]>=65 && caracter[0]<=90) || (caracter[0]>=97 && caracter[0]<=122) || caracter[0]==32)
		{
			std::cout<<caracter[0];
			*(lectura+i)=caracter[0];
			i++;
		}
		else
		{
			if(caracter[0]==13)
			{
				flag=false;
			}
			else
			{
				if(caracter[0]==8 && i>0)
				{
					*(lectura+i-1)='\0';
					std::cout<< "\b \b";
					i--;
				}
			}
		}
	}
	*(lectura+i)='\0';
	return lectura;

}
char * Ingreso::ingresoNumero(char * mensage) {
	printf("%s ",mensage);

	bool flag=true;
	char caracter[]="";
	char *lectura=(char*)malloc(sizeof(char));
	int i=0;

	while(flag){

		caracter[0]= getch();

		if((caracter[0]>=48 && caracter[0]<=57))
		{
			std::cout<<caracter[0];
			*(lectura+i)=caracter[0];
			i++;
		}
		else
		{
			if(caracter[0]==13)
			{
				flag=false;
			}
			else
			{
				if(caracter[0]==8 && i>0)
				{
					*(lectura+i-1)='\0';
					std::cout<< "\b \b";
					i--;
				}
			}
		}
	}
	*(lectura+i)='\0';
	return lectura;

}
char * Ingreso::ingresoCorreo(char * mensage) {
	printf("%s ",mensage);

	bool flag=true;
	char caracter[]="";
	char *lectura=(char*)malloc(sizeof(char));
	bool validar=true;
	int i=0;

	while(flag){

		caracter[0]= getch();

		if((caracter[0]>=48 && caracter[0]<=57) || (caracter[0]>=97 && caracter[0]<=122) || caracter[0]==64|| caracter[0]==46 || caracter[0]==95)
		{
			std::cout<<caracter[0];
			*(lectura+i)=caracter[0];
			i++;
			if(caracter[0]==64){
                validar=false;
			}
		}
		else
		{
			if(caracter[0]==13)
			{
				flag=false;
			}
			else
			{
				if(caracter[0]==8 && i>0)
				{
					*(lectura+i-1)='\0';
					std::cout<< "\b \b";
					i--;
				}
			}
		}
	}
	*(lectura+i)='\0';
	if(validar){
        printf("\nCORREO NO VALIDO VUELVA A INGRESAR\n");
        free(lectura);
        lectura=ingresoCorreo(mensage);
	}

	return lectura;

}
