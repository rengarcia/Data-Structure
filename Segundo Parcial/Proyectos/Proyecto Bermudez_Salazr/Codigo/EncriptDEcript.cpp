#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


string encrypt(string key, string message) {

        string newMessage = "";
        char letter;                

        for (int i = 0; i < strlen(message.c_str()); i++) {
            letter = message.at(i);
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
                newMessage = newMessage + key + letter;
            } else {
                newMessage = newMessage + letter;
            }
        }

        return newMessage;
    }
    
    
    string decrypt(string key, string message) {

        string newMessage = "";
        string auxiliarKey = "";
        char letter;
        for (int i = 0; i < strlen(message.c_str()); i++) {
            if (i < strlen(message.c_str()) - 2) {
                letter = message.at(i + 2);
                auxiliarKey = message.at(i) + message.at(i + 1);
                if (strcmp(key.c_str(), auxiliarKey.c_str())
                        && (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
                        || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I'
                        || letter == 'O' || letter == 'U')) {
                    newMessage = newMessage + message.at(i + 2);
                    i = i + 2;
                } else {
                    newMessage = newMessage + message.at(i);
                }
            } else {
                newMessage = newMessage + message.at(i);
            }

        }
        return newMessage;
    }
    
    int main(){
    	ifstream enter;
    	enter.open("encriptar.txt",ios::in);
    	string clave;
    	string mensaje;
    	cout<< "Ingrese la Clave"<<endl;
    	cin>>clave;    	
    	
    	while(!enter.eof()){
    		getline(enter,mensaje);
			    		
		}
    	mensaje = encrypt(clave,mensaje);
    	cout << mensaje << endl;
    	
    	cout << decrypt(clave,mensaje);
    	
    	
    	return 0;
	}




