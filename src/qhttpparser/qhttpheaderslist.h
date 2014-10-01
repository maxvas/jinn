#ifndef QHTTPHEADERSLIST_H
#define QHTTPHEADERSLIST_H

#include <QString>
#include <QVector>
#include <QHash>
#include "qhttpheader.h"
#include "qhttpparser_global.h"

class QHTTPPARSERSHARED_EXPORT QHttpHeadersList
{
public:
    QHttpHeadersList();
    void set(QString key, QString value);
    void setIfAbsent(QString key, QString value);
    void remove(QString key);
    bool contains(QString key);
    QString get(QString key);
    void clear();

    class iterator
    {
        public:
        iterator(QVector< QHttpHeader* >::iterator _arrayIterator)
            :_arrayIterator(_arrayIterator)
        {
        }

        QHttpHeader& operator*()
        {
            return **_arrayIterator;
        }

        bool operator!=( const iterator& val) const
        {
            return _arrayIterator!=val._arrayIterator;
        }

        iterator& operator++()
        {
            _arrayIterator++;
            return *this;
        }

    private:
            QVector< QHttpHeader* >::iterator _arrayIterator;
    };

    iterator begin(){
        return iterator(headers.begin());
    }

    iterator end(){
        return iterator(headers.end());
    }

private:
    QHash<QString, QHttpHeader *> hash;
    QVector< QHttpHeader * > headers;

};

#endif // QHTTPHEADERSLIST_H
