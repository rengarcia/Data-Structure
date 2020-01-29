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
#include "correcto.h"
#include "ui_correcto.h"

Correcto::Correcto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Correcto)
{
    ui->setupUi(this);
}

Correcto::~Correcto()
{
    delete ui;
}
