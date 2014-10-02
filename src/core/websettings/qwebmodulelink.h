#ifndef QWEBMODULELINK_H
#define QWEBMODULELINK_H

#include <QJSMapping>
#include <QDir>

class QWebModuleLink : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_QSTRING("url", url, setUrl)
    QJS_MAPPING_QSTRING("mdlFile", mdlFile, setMdlFile)

};

#endif // QWEBMODULELINK_H
