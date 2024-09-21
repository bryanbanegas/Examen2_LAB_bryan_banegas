#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "QString"

class empleado
{
protected:
    QString nombre;
    int edad;
    float salario;
public:
    empleado(QString& nombre, int edad, float salario):
        nombre(nombre), edad(edad), salario(salario){}

    QString getNombre(){
        return nombre;
    }

    int getEdad(){
        return edad;
    }

    float getSalario(){
        return salario;
    }

    double virtual calcularSalario(){}
};

#endif // EMPLEADO_H
