#ifndef EMPLEADOCONTRATADO_H
#define EMPLEADOCONTRATADO_H
#include "empleado.h"

class empleadoContratado : public empleado
{
private:
    int horas;
public:
    empleadoContratado(QString& nombre, int edad, float salario, int horas):
        empleado(nombre,edad,salario), horas(horas){}

    double calcularSalario(){
        return salario*horas;
    }
};

#endif // EMPLEADOCONTRATADO_H
