#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFile"
#include "estudiante.h"
#include "estudiantelicenciatura.h"
#include "estudiantemaestria.h"

#include "vehiculo.h"
#include "auto.h"
#include "camion.h"

#include "empleado.h"
#include "empleadocontratado.h"
#include "empleadofijo.h"

#include "publicacion.h"
#include "libro.h"
#include "revista.h"
#include "articulocientifico.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_agregarEstudiante_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_agregarMateria_clicked();

    void on_imprimiEstudiantes_clicked();

    void on_guardarEnArchivo_clicked();

    void on_agregarVehiculo_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_imprimiEstudiantes_2_clicked();

    void on_guardarEnArchivo_2_clicked();

    void on_agregarEmpleado_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_imprimiEstudiantes_3_clicked();

    void on_agregarPublicacion_clicked();

    void on_comboBox_4_currentIndexChanged(int index);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_eliminarPublicacion_clicked();

    void on_imprimiEstudiantes_4_clicked();

    void on_guardarEnArchivo_4_clicked();

    void on_guardarEnArchivo_3_clicked();

private:
    Ui::MainWindow *ui;
    QVector<estudiante*> estudiantes;
    int tipoEstudiante=0;
    QVector<vehiculo*> vehiculos;
    int tipoVehiculo=0;
    QVector<empleado*> empleados;
    int tipoEmpleado=0;
    QVector<publicacion*> publicaciones;
    int tipoPublicacion=0;
    bool disponible=true;
};
#endif // MAINWINDOW_H
