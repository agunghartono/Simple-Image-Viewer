/****************************************************************************
** A Simple Application to open image files using Qt Framework (C++)
** Written by Agung Hartono
** This code is free to be used to anyone
** But please notice me if you want to distribute the whole part of this code
** Also any comments to the code, let me know
** email: agunghartono1000@gmail.com
****************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.resize(600,400);
    window.show();
    return app.exec();
}
