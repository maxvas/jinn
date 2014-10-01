#include "qhttpheaderslist.h"

QHttpHeadersList::QHttpHeadersList()
{
}

void QHttpHeadersList::set(QString key, QString value)
{
    if (contains(key))
        remove(key);
    QHttpHeader *header = new QHttpHeader(key, value);
    hash[key.toLower()] = header;
    headers.append(header);
}

void QHttpHeadersList::setIfAbsent(QString key, QString value)
{
    if (contains(key))
        return;
    set(key, value);
}

void QHttpHeadersList::remove(QString key)
{
    if (!hash.contains(key.toLower()))
        return;
    QHttpHeader *header = hash[key.toLower()];
    int pos = headers.indexOf(header);
    if (pos==-1)
        return;
    hash.remove(key.toLower());
    headers.remove(pos);
}

bool QHttpHeadersList::contains(QString key)
{
    return hash.contains(key.toLower());
}

QString QHttpHeadersList::get(QString key)
{
    if (hash.contains(key.toLower()))
        return hash[key.toLower()]->value();
    return "";
}

void QHttpHeadersList::clear()
{
    hash.clear();
    headers.clear();
}
