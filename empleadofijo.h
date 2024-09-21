#ifndef EMPLEADOFIJO_H
#define EMPLEADOFIJO_H
#include "empleado.h"

class empleadoFijo : public empleado
{
public:
    empleadoFijo(QString& nombre, int edad, float salario):
        empleado(nombre,edad,salario){}

    double calcularSalario(){
        return salario;
    }
};

#endif // EMPLEADOFIJO_H
