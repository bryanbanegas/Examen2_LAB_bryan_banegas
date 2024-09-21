#ifndef LIBRO_H
#define LIBRO_H
#include "publicacion.h"

class libro : public publicacion
{
private:
    int numeroPaginas;
public:
    libro(QString& titulo, QString& autor, int anioPublicacion, bool disponible, int numeroPaginas):
        publicacion(titulo,autor,anioPublicacion,disponible),numeroPaginas(numeroPaginas){}

    QString getInfo(){
        QString info;
        if(disponible){
            info="Titulo: "+titulo+" Autor: "+autor+" Year: "+QString::number(anioPublicacion)+" Disponible para prestamo"+"\n";
            info+="Numero de Paginas: "+QString::number(numeroPaginas)+"\n";
        }else{
            info="Titulo: "+titulo+" Autor: "+autor+" Year: "+QString::number(anioPublicacion)+" No Disponible para prestamo"+"\n";
            info+="Numero de paginas: "+QString::number(numeroPaginas)+"\n";
        }
        return info;
    }
};

#endif // LIBRO_H
