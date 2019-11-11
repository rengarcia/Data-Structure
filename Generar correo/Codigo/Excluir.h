/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h> 


using namespace std;

class Excluir{
	public: 
		bool control(string s){
			int d=0;
    		for(int i=0;i<s.size();i++)
    		{
        		if(!isdigit(s[i])){
        		cout<<"Error"<<endl;
				return false;
				}
    		}
			return true;
		}
		
		bool controlS(string s){
			int d=0;
    		for(int i=0;i<s.size();i++)
    		{
        		if(isdigit(s[i])&&s[i]!=' '){
        		cout<<"Error"<<endl;
				return false;
				}
    		}
			return true;
		}
		
		bool controlSN(string s){
			int d=0;
    		for(int i=0;i<s.size();i++)
    		{
        		if(!isdigit(s[i])){
        		cout<<"Error"<<endl;
				return false;
				}
    		}
			return true;
		}
};
