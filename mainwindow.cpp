/****************************************************************************
** A Simple Application to open image files using Qt Framework (C++)
** Written by Agung Hartono
** This code is free to be used to anyone
** But please notice me if you want to distribute the whole part of this code
** Also any comments to the code, let me know
** email: agunghartono1000@gmail.com
****************************************************************************/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Constructor is to set all initial displays and interfaces up.

    //1. Setting QScrollArea
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::darkGray);
    scrollarea.setPalette(pal);
    scrollarea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollarea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollarea.setWidget(&label);       //1.a. Setting QLabel to QScrollArea
    scrollarea.setAlignment(Qt::AlignCenter);
    scrollarea.setFrameStyle(0);
    setCentralWidget(&scrollarea);      //1.b. Setting QScrollArea as QMainWindow's central widget

    //2. Setting QLabel
    label.setScaledContents(true);

    //3. Setting QToolBar and its action buttons
    //3.a. Setting button icons
    spacerleft.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    spacerright.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    open.setIcon(style()->standardPixmap(QStyle::SP_DirOpenIcon));
    zoomout.setIcon(QPixmap(":/images/resources/zoomout.png"));
    zoomin.setIcon(QPixmap(":/images/resources/zoomin.png"));
    previous.setIcon(style()->standardPixmap(QStyle::SP_ArrowLeft));
    next.setIcon(style()->standardPixmap(QStyle::SP_ArrowRight));

    //3.b. Setting buttons arrangement in QToolBar
    toolbar.setMovable(false);
    addToolBar(Qt::BottomToolBarArea, &toolbar);
    toolbar.addWidget(&spacerleft);
    toolbar.addSeparator();
    toolbar.addAction(&open);
    toolbar.addSeparator();
    toolbar.addAction(&zoomout);
    toolbar.addAction(&zoomin);
    toolbar.addSeparator();
    toolbar.addAction(&previous);
    toolbar.addAction(&next);
    toolbar.addSeparator();
    toolbar.addWidget(&spacerright);

    //4. Interfaces with the action buttons
    connect(&open, SIGNAL(triggered()), this, SLOT(FileOpen()));
    connect(&zoomout, SIGNAL(triggered()), this, SLOT(OnZoomOut()));
    connect(&zoomin, SIGNAL(triggered()), this, SLOT(OnZoomIn()));
    connect(&previous, SIGNAL(triggered()), this, SLOT(GoPrevious()));
    connect(&next, SIGNAL(triggered()), this, SLOT(GoNext()));
}

void MainWindow::keyPressEvent(QKeyEvent *event) //keyboard interface
{
    switch (event->key())
    {
    case Qt::Key_A:
        OnZoomOut();
        break;
    case Qt::Key_S:
        OnZoomIn();
        break;
    case Qt::Key_D:
        GoPrevious();
        break;
    case Qt::Key_F:
        GoNext();
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::FileOpen() //conducting image files open
{
    idx = 0;
    stringlist = QFileDialog::getOpenFileNames(this, "Open Images", "", "Image Files (*.jpg *.jpeg *.png *.gif *.bmp)");
    if (!stringlist.isEmpty())
    {
        label.setPixmap(QPixmap(stringlist.at(idx)));
        label.adjustSize();

        QFileInfo fileinfo (stringlist.at(idx));
        setWindowTitle(fileinfo.fileName());
    }
}

void MainWindow::OnZoomOut() //zooming out image
{
    label.resize(0.75 * label.size());
}

void MainWindow::OnZoomIn() //zooming in image
{
    label.resize(1.25 * label.size());
}

void MainWindow::GoPrevious() //going to previous image
{
    if (idx>0)
    {
        label.setPixmap(QPixmap(stringlist.at(--idx)));
        label.adjustSize();
        scrollarea.verticalScrollBar()->setValue(0);

        QFileInfo fileinfo (stringlist.at(idx));
        setWindowTitle(fileinfo.fileName());
    }
}

void MainWindow::GoNext() //going to next image
{
    if (idx<stringlist.size()-1)
    {
        label.setPixmap(QPixmap(stringlist.at(++idx)));
        label.adjustSize();
        scrollarea.verticalScrollBar()->setValue(0);

        QFileInfo fileinfo (stringlist.at(idx));
        setWindowTitle(fileinfo.fileName());
    }
}

