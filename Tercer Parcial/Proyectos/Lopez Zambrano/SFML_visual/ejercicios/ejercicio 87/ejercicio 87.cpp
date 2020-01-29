// ejercicio 87.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
string representacionNota(double calificacion);
int main()
{
    double calificacion = ingresarDouble("Ingrese nota: ");
    cout << "la nota de " << calificacion << " es " << representacionNota(calificacion) << endl;
}

string representacionNota(double calificacion)
{
    if (calificacion >= 0 && calificacion < 5)
        return "<<Suspenso>>";
    else if (calificacion >= 5 && calificacion < 7)
        return "<<Aprobado>>";
    else if (calificacion >= 7 && calificacion < 8.5)
        return "<<Notable>>";
    else if (calificacion >= 8.5 && calificacion < 10)
        return "<<Sobresaliente>>";
    else if (calificacion == 10)
        return "<<Matricula de Honor>>";
    else
        return "error";
}
