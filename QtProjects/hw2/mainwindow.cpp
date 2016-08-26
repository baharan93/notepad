#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItem>
#include <QTextEdit>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setfilename(QString &name){
    this->filename = name;
}

void MainWindow::on_actionNew_triggered()
{
    if(!ui->text->toPlainText().isEmpty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "This is an alart", "Do you want to save current file",
                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes){
            MainWindow::on_actionSave_as_triggered();
            ui->text->clear();
        }else{
            ui->text->clear();
        }
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "choose a file", "/home/baharan");
    ui->statusBar->showMessage(filename);
    QFile file(filename);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream input (&file);
    ui->text->setPlainText(input.readAll());
    file.close();
}

void MainWindow::on_actionSave_triggered()
{   if (this->filename.isEmpty())
    {
    QString filename = QFileDialog::getSaveFileName(this, "save this file", "/home/baharan");
    ui->statusBar->showMessage(filename);
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream stream (&file);
    stream << ui->text->toPlainText();
    file.flush();
    this->setfilename(filename);
    file.close();
    }else{

        ui->statusBar->showMessage(filename);
        QFile file(filename);
        file.open(QFile::WriteOnly | QFile::Text);
        QTextStream stream (&file);
        stream << ui->text->toPlainText();
        file.flush();
        file.close();
    }
}
void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "save this file", "/home/baharan");
    ui->statusBar->showMessage(filename);
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream stream (&file);
    stream << ui->text->toPlainText();
    stream.flush();
    file.close();

}

void MainWindow::on_actionCut_triggered()
{
    ui->text->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->text->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->text->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->text->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->text->undo();
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::about(this, "About", "This is my first project in Qt.\nIt has a problem in the save action.\n"
           "I think the project must have a timer to determine the first time that the save action is trigerred.\nBAHARAN");
}
