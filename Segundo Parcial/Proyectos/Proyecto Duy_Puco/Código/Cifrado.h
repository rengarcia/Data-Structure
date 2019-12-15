/***********************************************************************
 * Module:  Cifrado.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Declaration of the class Cifrado
 ***********************************************************************/
 
class Cifrado {
	 private:
	 	char *cadena; //cadena en la que se carga el archivo
	 	long tamanio; //tamaño del archivo
	 public:
	 	~Cifrado();
		 void leer( const char* );
		 void cifrar( const char* );
		 void descifrar( const char* );
		 void grabar( const char* );
};
