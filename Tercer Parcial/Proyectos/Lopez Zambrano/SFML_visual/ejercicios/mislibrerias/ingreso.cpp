/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Zambrano Andrés
Fecha Creacion: 118/01/2020
Estructura de Datos
Ing. Fernando Solis
*/
#include "ingreso.h"
string ingresarCualquierCosa(string msg)
{
    string texto;
    cout << msg << endl;
    getline(cin, texto);
    return texto;
}

string ingresarPalabra(string msg)
{
    string texto;
    while (1)
    {
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        cin >> texto;
        try {
            for (size_t i = 0; i < texto.length(); i++) {

                if (!isalpha(texto[i])) {
                    if (texto[i] == ' ') {
                        continue;
                    }
                    else {
                        cout << "Se debe ingresar solo letras\n";
                        is_valid = false;
                        break;
                    }

                }


            }
        }
        catch (exception e) {
            cout << "error";
        }

        if (is_valid) {
            break;
        }
    }
    return texto;
}

char ingresarCaracter(string msg)
{
    char caracter;
    string texto;
    while (1)
    {
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        cin >> texto;
        if (texto.length() > 1) {
            is_valid = false;
            cout << "Solo debe ingresar 1 caracter" << endl;
        }

        if (is_valid) {
            caracter = texto.at(0);
            break;
        }
    }
    return caracter;
}

string ingresarSoloTexto(string msg) {
    string res;
    while (1)
    {
        string texto;
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        getline(cin, texto);
        try {
            for (size_t i = 0; i < texto.length(); i++) {

                if (!isalpha(texto[i])) {
                    if (texto[i] == ' ') {
                        continue;
                    }
                    else {
                        cout << "Se debe ingresar solo letras\n";
                        is_valid = false;
                        break;
                    }

                }


            }
        }
        catch (exception e) {
            cout << "error";
        }

        if (is_valid) {
            res = texto;
            break;
        }
    }
    return res;
}

float ingresarFlotante(string msg) {
    float valor;
    string numero;

    while (1)
    {
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        cin >> numero;
        try {
            for (size_t i = 0; i < numero.length(); i++) {

                if (!isdigit(numero[i])) {
                    if (numero[i] == '-') {
                        continue;
                    }
                    if (!(numero[i] == '.')) {
                        cout << "Se debe ingresar numeros\n";
                        is_valid = false;
                        break;
                    }
                }
            }
        }
        catch (exception e) {
            cout << "error";
        }

        if (is_valid) {
            stringstream geek(numero);
            geek >> valor;
            break;
        }
    }
    return valor;
}

double ingresarDouble(string msg) {
    double valor;
    string numero;

    while (1)
    {
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        cin >> numero;
        try {
            for (size_t i = 0; i < numero.length(); i++) {

                if (!isdigit(numero[i])) {
                    if (!(numero[i] == '.')) {
                        cout << "Se debe ingresar numeros\n";
                        is_valid = false;
                        break;
                    }
                }
            }
        }
        catch (exception e) {
            cout << "error";
        }

        if (is_valid) {
            stringstream geek(numero);
            geek >> valor;
            break;
        }
    }
    return valor;
}

int ingresarBinario(string msg)
{
    int valor;
    string numero;
    while (1)
    {
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        cin >> numero;
        try {
            for (size_t i = 0; i < numero.length(); i++) {
                if (!isdigit(numero.at(i))) {
                    cout << "Se debe ingresar numeros" << endl;
                    is_valid = false;
                    break;
                }
                if (isdigit(numero.at(i))) {
                    if (numero.at(i) == '0' || numero.at(i) == '1') {
                        continue;
                    }
                    else {
                        cout << "Se debe ingresar solo 0 y 1" << endl;
                        is_valid = false;
                        break;
                    }
                }
            }
        }
        catch (exception e) {
            cout << "error";
        }

        if (is_valid) {
            valor = stoi(numero);
            break;
        }
    }
    return valor;
}

int ingresarEntero(string msg) {
    int valor;
    string numero;
    int vecessigno = 1;
    while (1)
    {
        fflush(stdin);
        bool is_valid = true;
        cout << msg << endl;
        cin >> numero;
        try {
            for (size_t i = 0; i < numero.length(); i++) {
                if (vecessigno > 0 && numero.at(i) == '-') {
                    vecessigno = 0;
                    continue;
                }
                if (!isdigit(numero.at(i))) {
                    cout << "Se debe ingresar numeros\n";
                    is_valid = false;
                    break;

                }
            }
        }
        catch (exception e) {
            cout << "error";
        }

        if (is_valid) {
            valor = stoi(numero);
            break;
        }
    }
    return valor;
}

bool validarCedula(int cedula) {
    int ced, pares, impares, total, dec = 0;
    int primerDigito;
    int segundoDigito;
    int tercerDigito;
    int cuartoDigito;
    int quintoDigito;
    int sextoDigito;
    int septimoDigito;
    int octavoDigito;
    int novenoDigito;
    int decimoDigito;
    //cout<<"Ingrese su cedula: "<<endl;
    //cin>>cedula;
    ced = cedula;

    primerDigito = cedula / 1000000000;
    cedula = cedula - (primerDigito * 1000000000);
    segundoDigito = cedula / 100000000;
    cedula = cedula - (segundoDigito * 100000000);
    tercerDigito = cedula / 10000000;
    cedula = cedula - (tercerDigito * 10000000);
    cuartoDigito = cedula / 1000000;
    cedula = cedula - (cuartoDigito * 1000000);
    quintoDigito = cedula / 100000;
    cedula = cedula - (quintoDigito * 100000);
    sextoDigito = cedula / 10000;
    cedula = cedula - (sextoDigito * 10000);
    septimoDigito = cedula / 1000;
    cedula = cedula - (septimoDigito * 1000);
    octavoDigito = cedula / 100;
    cedula = cedula - (octavoDigito * 100);
    novenoDigito = cedula / 10;
    cedula = cedula - (novenoDigito * 10);
    decimoDigito = cedula / 1;
    cedula = cedula - (decimoDigito * 1);

    if (cedula > 2400000000) {
        cout << "Numero de cedula invalido." << endl;
        return false;
    }
    else {

        pares = segundoDigito + cuartoDigito + sextoDigito + octavoDigito;

        primerDigito = primerDigito * 2;
        if (primerDigito > 9) {
            primerDigito = primerDigito % 10 + primerDigito / 10;
        }

        tercerDigito = tercerDigito * 2;
        if (tercerDigito > 9) {
            tercerDigito = tercerDigito % 10 + tercerDigito / 10;
        }

        quintoDigito = quintoDigito * 2;
        if (quintoDigito > 9) {
            quintoDigito = quintoDigito % 10 + quintoDigito / 10;
        }

        septimoDigito = septimoDigito * 2;
        if (septimoDigito > 9) {
            septimoDigito = septimoDigito % 10 + septimoDigito / 10;
        }

        novenoDigito = novenoDigito * 2;
        if (novenoDigito > 9) {
            novenoDigito = novenoDigito % 10 + novenoDigito / 10;
        }

        impares = primerDigito + tercerDigito + quintoDigito + septimoDigito + novenoDigito;

        total = pares + impares;



        while (dec - total != decimoDigito && dec < total + 10) {
            dec = dec + 10;
        }

        if (dec - total == decimoDigito) {
            return true;
        }
        else {
            return false;
        }




    }

}
