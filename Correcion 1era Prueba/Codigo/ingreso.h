/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Entry
{
public:
    float enterokay(char *);
    bool validate(string);
};

float Entry::enterokay(char *msg)
{
    string numero;
    bool flag;
    do
    {
        try
        {
            cout << msg;
            getline(cin, numero);
            flag = validate(numero);
            if (flag)
            {
                throw numero;
            }
        }
        catch (string e)
        {
            cout << "Dato invalido " << e << endl;
        }
    } while (flag);

    return atof(numero.c_str());
}

bool Entry::validate(string valor)
{
    bool flag;
    for (int i = 0; i < valor.length(); i++)
    {
        if (isdigit(valor[i]))
        {
            flag = false;
        }
        else
        {
            if (valor[i] == '.')
            {
                flag = false;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}
