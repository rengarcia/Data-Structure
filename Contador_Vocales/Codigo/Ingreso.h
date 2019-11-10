#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


class Ingreso {

public:
	char * leer(char *mensage);
};

char * Ingreso::leer(char * mensage) {
	printf("%s ",mensage);

	bool flag=true;
	char caracter[]="";
	char *lectura=(char*)malloc(sizeof(char));
	int i=0;

	while(flag){

		caracter[0]= getch();

		if((caracter[0]>=65 && caracter[0]<=90) || (caracter[0]>=97 && caracter[0]<=122))
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
