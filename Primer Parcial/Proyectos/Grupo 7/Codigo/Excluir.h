#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h> 

//Universidad de las Fuerzas Armdas
//Nombre: Kevin Zurita
//NRC: 2967
//Fecha de creacion: 23/09/2019
//FecHa de ultima modificacion: 24/09/2019

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
        		if(isdigit(s[i])){
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
