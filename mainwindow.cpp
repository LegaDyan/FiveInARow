#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->label, SIGNAL(dropChess(QString)), this, SLOT(sendMessage(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
    connectHost();
}

void MainWindow::connectHost() {
    this->readWriteSocket = new QTcpSocket;
    this->readWriteSocket->connectToHost(QHostAddress::LocalHost, 8888);
    QObject::connect(this->readWriteSocket, SIGNAL(readyRead()), this, SLOT(recvMessage()));
}

void MainWindow::recvMessage() {
    QString info;
    info = this->readWriteSocket->readAll();
    ui->label->addOppo(info);
}

void MainWindow::sendMessage(QString info) {
    QByteArray *array = new QByteArray;
    array->clear();
    array->append(info);
    this->readWriteSocket->write(array->data());
}
