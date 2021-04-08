#ifndef TCPUDP_H
#define TCPUDP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpUdp : public QObject
{
    Q_OBJECT
public:
    explicit TcpUdp(QObject *parent = nullptr);
    void Send();

signals:

private:
    QTcpServer *server;

public slots:
    void acceptConnection();

};

#endif // TCPUDP_H
