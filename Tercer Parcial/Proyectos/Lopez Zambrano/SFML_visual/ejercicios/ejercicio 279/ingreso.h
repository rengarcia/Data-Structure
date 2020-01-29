#pragma once
/**
  * @file ingreso.h
  * @version 1.0
  * @date 14/10/2019
  * @author Zambrano Andres
  * @title Ingreso
  */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream> 
#include <stdlib.h>
using namespace std;
string ingresarCualquierCosa(string msg);
string ingresarSoloTexto(string msg);
int ingresarEntero(string msg);
float ingresarFlotante(string msg);
double ingresarDouble(string msg);
bool validarCedula(int cedula);
char ingresarCaracter(string msg);
string ingresarPalabra(string msg);