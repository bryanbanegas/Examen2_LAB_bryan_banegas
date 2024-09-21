#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_agregarEstudiante_clicked()
{
    QString nombre=ui->lineEdit->text();
    int edad=ui->lineEdit_2->text().toInt();
    estudiante* nuevoEstudiante;
    if(tipoEstudiante==0){
        nuevoEstudiante=new estudianteLicenciatura(nombre,edad);
    }else{
        nuevoEstudiante=new estudianteMaestria(nombre,edad);
    }
    estudiantes.append(nuevoEstudiante);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    tipoEstudiante=index;
}


void MainWindow::on_agregarMateria_clicked()
{
    QString nombreEstudiante=ui->lineEdit_3->text();
    QString nombre=ui->lineEdit_4->text();
    int calificacion=ui->lineEdit_5->text().toInt();
    for(int i=0;i<estudiantes.size();i++){
        if(estudiantes.at(i)->getNombre()==nombreEstudiante){
            estudiantes.at(i)->agregarMateria(nombre,calificacion);
        }
    }
}


void MainWindow::on_imprimiEstudiantes_clicked()
{
    QString info="";
    for(int i=0;i<estudiantes.size();i++){
        info+="Nombre: "+estudiantes.at(i)->getNombre()+" Edad: "+QString::number(estudiantes.at(i)->getEdad())+"\n";
        info+="Promedio: "+QString::number(estudiantes.at(i)->promedio())+"\n";
    }
    ui->textEdit->setText(info);
}


void MainWindow::on_guardarEnArchivo_clicked()
{
    QString archivoNombre="estudiantes.txt";
    QFile archivo(archivoNombre);
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&archivo);
        for(int i=0;i<estudiantes.size();i++){
            stream<<estudiantes.at(i)->getNombre()+" "+QString::number(estudiantes.at(i)->getEdad())+"\n";
            for(int c=0;c<estudiantes.at(i)->getMaterias().size();c++){
                stream<<estudiantes.at(i)->getMaterias().at(c)+" "+QString::number(estudiantes.at(i)->getCalificaciones().at(c))+"\n";
            }
        }
        archivo.close();
    }
}


void MainWindow::on_agregarVehiculo_clicked()
{
    QString modelo=ui->lineEdit_6->text();
    int year=ui->lineEdit_7->text().toInt();
    QString kilometerpueba=ui->lineEdit_8->text();
    bool ok;
    float kilometer=kilometerpueba.toFloat(&ok);

    vehiculo* nuevoVehiculo;
    if(tipoVehiculo==1){
        nuevoVehiculo=new automovil(modelo,year,kilometer);
    }else{
        int peso=ui->lineEdit_9->text().toInt();
        nuevoVehiculo=new camion(modelo,year,kilometer,peso);
    }

    vehiculos.append(nuevoVehiculo);
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    tipoVehiculo=index;
    switch(tipoVehiculo){
    case 1:
        ui->lineEdit_9->setVisible(false);
        ui->label_10->setVisible(false);
        break;
    case 0:
        ui->lineEdit_9->setVisible(true);
        ui->label_10->setVisible(true);
        break;
    }
}


void MainWindow::on_imprimiEstudiantes_2_clicked()
{
    QString info="";
    for(int i=0;i<vehiculos.size();i++){
        info+="Modelo: "+vehiculos.at(i)->getModelo()+" Year: "+QString::number(vehiculos.at(i)->getYear())+"\n";
        info+="Mantenimiento: "+QString::number(vehiculos.at(i)->calcularMantenimiento())+"\n";
    }
    ui->textEdit_2->setText(info);
}


void MainWindow::on_guardarEnArchivo_2_clicked()
{
    QString archivoNombre="vehiculos.txt";
    QFile archivo(archivoNombre);
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&archivo);
        for(int i=0;i<vehiculos.size();i++){
            stream<<vehiculos.at(i)->getModelo()+" "+QString::number(vehiculos.at(i)->getYear())+"\n";
        }
        archivo.close();
    }
}


void MainWindow::on_agregarEmpleado_clicked()
{
    QString nombre=ui->lineEdit_13->text();
    int edad=ui->lineEdit_12->text().toInt();
    QString salarioprueba=ui->lineEdit_10->text();
    bool ok;
    float salario=salarioprueba.toFloat(&ok);

    empleado* nuevoEmpleado;
    if(tipoEmpleado==1){
        nuevoEmpleado=new empleadoFijo(nombre,edad,salario);
    }else{
        int horas=ui->lineEdit_11->text().toInt();
        nuevoEmpleado=new empleadoContratado(nombre,edad,salario,horas);
    }

    empleados.append(nuevoEmpleado);
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    tipoEmpleado=index;
    switch(tipoEmpleado){
    case 1:
        ui->lineEdit_11->setVisible(false);
        ui->label_14->setVisible(false);
        break;
    case 0:
        ui->lineEdit_11->setVisible(true);
        ui->label_14->setVisible(true);
        break;
    }
}


void MainWindow::on_imprimiEstudiantes_3_clicked()
{
    QString info="";
    for(int i=0;i<empleados.size();i++){
        info+="Nombre: "+empleados.at(i)->getNombre()+" Edad: "+QString::number(empleados.at(i)->getEdad())+"\n";
        info+="Salario: "+QString::number(empleados.at(i)->calcularSalario())+"\n";
    }
    ui->textEdit_3->setText(info);
}


void MainWindow::on_agregarPublicacion_clicked()
{
    QString titulo=ui->lineEdit_14->text();
    QString autor=ui->lineEdit_15->text();
    int anioPublicacion=ui->lineEdit_17->text().toInt();
    publicacion* nuevaPublicacion;
    bool crear=true;
    if(tipoPublicacion==0){
        int dato=ui->lineEdit_18->text().toInt();
        nuevaPublicacion=new libro(titulo,autor,anioPublicacion,disponible,dato);
    }else if(tipoPublicacion==1){
        int dato=ui->lineEdit_18->text().toInt();
        nuevaPublicacion=new revista(titulo,autor,anioPublicacion,disponible,dato);
    }else{
        QString dato=ui->lineEdit_18->text();
        nuevaPublicacion=new articuloCientifico(titulo,autor,anioPublicacion,disponible,dato);
    }
    for(int i=0;i<publicaciones.size();i++){
        if(publicaciones.at(i)->getTitulo()==titulo){
            crear=false;
        }
    }
    if(crear){
        publicaciones.append(nuevaPublicacion);
    }
}


void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    tipoPublicacion=index;
}


void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        disponible=true;
        break;
    case 1:
        disponible=false;
        break;
    }
}


void MainWindow::on_eliminarPublicacion_clicked()
{
    QString nombre=ui->lineEdit_16->text();
    for(int i=0;i<publicaciones.size();i++){
        if(publicaciones.at(i)->getTitulo()==nombre){
            publicacion* eliminar=publicaciones.at(i);
            publicaciones.removeAt(i);
            delete eliminar;
        }
    }
}


void MainWindow::on_imprimiEstudiantes_4_clicked()
{
    QString info="";
    for(int i=0;i<publicaciones.size();i++){
        info+=publicaciones.at(i)->getInfo();
    }
    ui->textEdit_4->setText(info);
}


void MainWindow::on_guardarEnArchivo_4_clicked()
{
    QString archivoNombre="publicaciones.txt";
    QFile archivo(archivoNombre);
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&archivo);
        for(int i=0;i<publicaciones.size();i++){
            stream<<publicaciones.at(i)->getInfo()+"\n";
        }
        archivo.close();
    }
}


void MainWindow::on_guardarEnArchivo_3_clicked()
{
    QString archivoNombre="empleados.txt";
    QFile archivo(archivoNombre);
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&archivo);
        for(int i=0;i<empleados.size();i++){
            stream<<empleados.at(i)->getNombre()+" "+QString::number(empleados.at(i)->getEdad())+"\n";
        }
        archivo.close();
    }
}

