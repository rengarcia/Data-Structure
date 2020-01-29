/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#include "tsi.h"
#include "ui_tsi.h"
#include <iostream>
#include <string>
#include "ManejoArchivos.h"
#include "OperacionArbol.h"


using namespace std;
Tsi::Tsi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tsi)
{
    ui->setupUi(this);
}

Tsi::~Tsi()
{
    delete ui;
}

void Tsi::on_pushButton_clicked()
{
    ManejoArchivo controlador;
    Arbol *arbolE = NULL;
    Palabra palabraT;
    controlador.open_file_espanol(arbolE);
    OperacionArbol opAr;
    string result;
    QString palabra=ui->txtes->text();
    string vari = palabra.toStdString();
    controlador.convertirMayusculas(vari);
    palabraT.setClaveE(controlador.clave(vari));
    opAr.busquedaEspanol(arbolE, palabraT.getClaveE(),vari,result);
    ui->txting->setText(QString::fromStdString(result));
}
