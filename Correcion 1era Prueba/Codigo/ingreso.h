/**
  * @file ingreso.h
  * @version 1.0
  * @date 29/09/2019
  * @author Luis Carvajal
  * @title Clase Ingreso
  * @code
    int main(){
	main:
	int row,col,exp;
	Matriz p;
	printf("Ingrese # filas: ");
	scanf("%d",&row);
	printf("Ingrese # columnas: ");
	scanf("%d",&col);
	printf("\n");
	if(row>10&&row>10||row!=col){
		printf("la matriz tiene q ser cuadrada y su dimenion menor o igual q 10\n");
	}else{
		p.setcolumnas(col);
		p.setfilas(row);
		p.crear();
		p.llenar();
		p.imprimir();
		printf("ingrese el exponente: ");
		scanf("%d",&exp);
		p.multiplicar(exp);
		p.imprimir();
		
		
	}
	system("pause");
	system("cls");
	goto main;
	return 0;
  * @endcode
  * @brief Ingreso de datos 
  */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
/**
 * @brief Clase para el ingreo de datos
 */
class Ingreso{
public:
	/**
	  * @brief ingresarFloat Obtiene un float
	  * @return float
	  */
    float ingresarFloat(char*);
    
    /**
	  * @brief validarFloar Valida el float
	  * @return bool
	  */
    bool validarFloat(string);
    
    /**
	  * @brief ingresarInt Obtiene un int
	  * @return int
	  */
    int ingresarInt(char*);
    
    /**
	  * @brief validarInt Valida el int
	  * @return bool
	  */
    bool validarInt(string);
    
    /**
	  * @brief ingresarString Obtiene un string
	  * @return string
	  */
    string ingresarString(char*);
    
    /**
	  * @brief validarString Valida el string
	  * @return string
	  */
    bool validarString(string);
    
    /**
	  * @brief ingresar10Digitos Obtiene una cadena de longitud 10
	  * @return string
	  */
	string ingresar10Digitos(char*);
	
    /**
	  * @brief validar10Digitos Valida que la cadena sea de longitud 10 
	  * @return bool
	  */
    bool validar10Digitos(string);

};

/**
 * @brief Ingreso de dato float
 * @param char *msg
 * @return float
 */
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

/**
 * @brief Valida de dato double
 * @param string valor
 * @return bool
 */
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

/**
 * @brief Ingreso de dato int
 * @param char *msg
 * @return int
 */
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

/**
 * @brief Valida de dato int
 * @param string valor
 * @return bool
 */
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

/**
 * @brief Ingreso de un string
 * @param char *msg
 * @return string
 */
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

/**
 * @brief Valida un string
 * @param string valor
 * @return bool
 */
bool Ingreso::validarString(string valor){
    bool flag;
    for(int i = 0; i<valor.length(); i++){
        if(isalpha(valor[i]) || valor[i] == 32){
           flag = false;
        }else{
            return true;
        }
    }
    return flag;
}

/**
 * @brief Ingreso de 10 digitos
 * @param char *msg
 * @return string
 */
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

/**
 * @brief Valida 10 igitos
 * @param string valor
 * @return bool
 */
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


