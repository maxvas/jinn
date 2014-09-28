#ifndef PROXYMODULE_H
#define PROXYMODULE_H

#include <QObject>
#include <anutamodule.h>
#include <qhttpresponseparser.h>

class ProxyModule : public AnutaModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.maxvas.anuta_api.AnutaModule")
    Q_INTERFACES(AnutaModule)
public:
    explicit ProxyModule(QObject *parent = 0);
    QString name();

private:

signals:

public slots:

};

#endif // PROXYMODULE_H
