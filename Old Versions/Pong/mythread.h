#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
extern int cli_data;//CLIENT DAN GELECEK DATALAR
extern int cli_data2;


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int iID, QObject *parent = 0,QTcpServer *server=0, int id = 0);
    void run();
    int thread_id = 0;
signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readWrite();
    void disconnected();

public slots:

private:
    QTcpSocket *socket;
    int socketDescriptor;
    QTcpServer *tcpServer = nullptr;

};

#endif // MYTHREAD_H
