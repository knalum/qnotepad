/*
 * QNotepad : A text editor.
 * Konstantin Nalum 2020
 */

#include "mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("://img/appIcon.png"));

    a.setStyle(QStyleFactory::create("fusion"));
    //a.setStyle(QStyleFactory::create("windows"));
    //a.setStyle(QStyleFactory::create("osx"));

    MainWindow w;
    w.setWindowTitle("qnotepad");
    w.show();
    return a.exec();
}
