#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

const QString FILE_DIR = "/Users/knalum/qtFile.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::myfunction(){

}

void MainWindow::on_actionNew_triggered(){
    file_path = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionAbout_notepad_triggered(){
    QMessageBox::information(this,"About","QNotepad created by Konstantin Nalum");
}

void MainWindow::on_actionOpen_triggered(){
    auto fileName = QFileDialog::getOpenFileName(this,"Open the file",QDir::homePath());
    if( fileName.isEmpty() || fileName.isNull() ){
        return;
    }else{
        this->file_path = fileName;
    }

    QFile file(fileName);
    if( !file.open( QFile::ReadOnly | QFile::Text) ){
        QMessageBox::warning(this,"","Can't open file");
        return;
    }
    this->file_path = fileName;

    QTextStream in(&file);
    ui->textEdit->setText(file.readAll());
    file.close();
}

void MainWindow::on_actionSave_triggered(){

    if( this->file_path == nullptr ){
        auto fileName = QFileDialog::getSaveFileName(this,"Save");
        if( fileName.isEmpty() || fileName.isNull() ){
            return;
        }else{
            this->file_path = fileName;
        }
    }

    QFile file(this->file_path);

    if( !file.open(QFile::WriteOnly | QFile::Text) ){
        QMessageBox::warning(this,"","Can't open file");
        return;
    }

    QTextStream out(&file);
    auto str = ui->textEdit->toPlainText();
    out<<str;
    file.flush();
    file.close();
}



void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save");
    if( fileName.isEmpty() || fileName.isNull() ){
        return;
    }else{
        this->file_path = fileName;
    }

    QFile file(fileName);
    if( !file.open(QFile::WriteOnly | QFile::Text) ){
        QMessageBox::warning(this,"","Can't open file");
        return;
    }

    QTextStream out(&file);
    auto str = ui->textEdit->toPlainText();
    out<<str;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered(){
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered(){
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered(){
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered(){
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered(){
    ui->textEdit->undo();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}
