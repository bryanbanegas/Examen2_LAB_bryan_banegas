#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "QString"
#include "QVector"

class estudiante
{
protected:
    QString nombre;
    int edad;
    QVector<QString> materias;
    QVector<int> calificaciones;
public:
    estudiante(QString& nombre, int edad):
        nombre(nombre), edad(edad){}

    void agregarMateria(QString nombreMateria, int calificacion){
        materias.append(nombreMateria);
        calificaciones.append(calificacion);
    }

    QString getNombre(){
        return nombre;
    }

    int getEdad(){
        return edad;
    }

    QVector<QString> getMaterias(){
        return materias;
    }

    QVector<int> getCalificaciones(){
        return calificaciones;
    }

    double virtual promedio(){}
};

#endif // ESTUDIANTE_H
