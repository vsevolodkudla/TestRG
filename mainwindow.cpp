#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <random>

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

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(QFileDialog::getSaveFileName(this,
                                                       tr("Open file"), "/home"));
}

void MainWindow::on_commandLinkButton_clicked()
{
    std::ofstream fout(ui->lineEdit->text().toStdString().c_str());
    unsigned i, size;
    for (i = ui->fromEdit->text().toInt(); i < ui->fromEdit->text().toInt()+ui->callEdit->text().toInt();i++ )
    {
        fout << i << ' ';
        size = random()%ui->sizeEdit->text().toInt();
        fout << size << ' ';
        char t;
        for (int j = 0; j < size; j++)
        {
            t = 33+random()%93;
            fout << t;
        }

        qDebug() << sizeof(t);
        fout << '\0';
    }
    fout.close();
}

