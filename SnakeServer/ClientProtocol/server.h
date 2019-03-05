#ifndef SERVER_CP_H
#define SERVER_CP_H
#include "clientprotocol_global.h"
#include "clientprotocol.h"

#include <QTcpServer>

namespace ClientProtocol {


class CLIENTPROTOCOLSHARED_EXPORT Server : public QTcpServer
{
    Q_OBJECT
private:
    Package _downloadPackage;

    bool parsePackage(const Package &pkg, QTcpSocket * sender);

    bool sendPackage(Package &pkg, QTcpSocket * target);
private slots:
    void avelableBytes();
    void handleIncommingConnection();

public:
    explicit Server(QObject * ptr = nullptr);
    ~Server() override;
    bool run(const QString& ip, unsigned short port);

signals:
    void incomingReques(const QVariantMap &map, QTcpSocket * sender);
};

}
#endif // SERVER_CP_H
