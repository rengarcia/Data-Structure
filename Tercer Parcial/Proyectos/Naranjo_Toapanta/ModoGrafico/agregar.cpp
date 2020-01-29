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
#include "agregar.h"
#include "ui_agregar.h"
#include "ManejoArchivos.h"
#include <QRegExpValidator>

Agregar::Agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar)
{
    ui->setupUi(this);
    QRegExp rx("^[a-zA-Záéíóúñ]{3,16}$");
    QRegExpValidator *validar = new QRegExpValidator(rx,this);
    ui->lineEdit->setValidator(validar);
    ui->lineEdit_2->setValidator(validar);
}

Agregar::~Agregar()
{
    delete ui;
}

void Agregar::on_pushButton_clicked()
{
    ManejoArchivo controlador;
    controlador.agregar_Diccionario(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString());
    Correcto *ventana = new Correcto;
    ventana->show();
}

void Agregar::on_pushButton_2_clicked()
{
    MainWindow *ventana = new MainWindow;
    this->hide();
    ventana->show();

}

