#include "tcpudp.h"

TcpUdp::TcpUdp(QObject *parent) : QObject(parent)
{
    server=new QTcpServer(this);
    server->listen(QHostAddress::Any, 1500);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    Send();
}

void TcpUdp::Send()
{
    QByteArray data;
    data.append("Hola desde TCP");
    QTcpSocket *client=new QTcpSocket(this);
    client->connectToHost(QHostAddress::LocalHost, 1500);
    quint32 write_len=client->write(data);
    qDebug()<<"Escribiendo...";
    client->waitForBytesWritten(10000);

    client->disconnectFromHost();
    if(client->state()==QAbstractSocket::UnconnectedState || client->waitForDisconnected(10000)){
         qDebug()<<"Cliente cerrado...";
    }

}

void TcpUdp::acceptConnection()
{
    QTcpSocket *clientConnection=server->nextPendingConnection();
    QByteArray array;

    qDebug()<<"Leyendo...";

    while(clientConnection->waitForReadyRead(500)){
        qDebug()<<"bytes Disponibles"<<endl;
        array.append((QByteArray)clientConnection->readAll());
        qDebug()<<array;
    }
}
