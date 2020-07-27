/****************************************************************************
** A Simple Application to open image files using Qt Framework (C++)
** Written by Agung Hartono
** This code is free to be used to anyone
** But please notice me if you want to distribute the whole part of this code
** Also any comments to the code, let me know
** email: agunghartono1000@gmail.com
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QScrollBar>
#include <QLabel>
#include <QToolBar>
#include <QKeyEvent>
#include <QFileDialog>
#include <QFileInfo>
#include <QStyle>
#include <QUrl>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent*);
    ~MainWindow();
public slots:
    void FileOpen();
    void OnZoomOut();
    void OnZoomIn();
    void GoPrevious();
    void GoNext();
private:
    QScrollArea scrollarea;
    QLabel label;
    QToolBar toolbar;
    QWidget spacerleft, spacerright;
    QAction open, zoomout, zoomin, previous, next;
    QStringList stringlist;
    int idx;
};
#endif // MAINWINDOW_H
