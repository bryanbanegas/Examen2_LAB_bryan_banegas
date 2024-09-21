#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "QString"

class publicacion
{
protected:
    QString titulo;
    QString autor;
    int anioPublicacion;
    bool disponible;
public:
    publicacion(QString& titulo, QString& autor, int anioPublicacion, bool disponible):
        titulo(titulo), autor(autor), anioPublicacion(anioPublicacion), disponible(disponible){}

    QString getTitulo(){
        return titulo;
    }

    QString getAutor(){
        return autor;
    }

    int getYear(){
        return anioPublicacion;
    }

    bool getDisponible(){
        return disponible;
    }

    void setDisponible(bool disponibilidad){
        disponible=disponibilidad;
    }

    QString virtual getInfo(){}
};

#endif // PUBLICACION_H
