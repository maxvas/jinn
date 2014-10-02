#ifndef QWEBMODULE_H
#define QWEBMODULE_H

#include <QJSMapping>
#include "../core_global.h"
#include "qwebcontentpath.h"

class JINN_CORESHARED_EXPORT QWebModule : public QJSMapping
{
    Q_OBJECT
public:
    QWebModule(QJS data);
    QJS_MAPPING_QSTRING("name", name, setName)
    QJS_MAPPING_QSTRING("url", url, setUrl)
    QJS_MAPPING_ARRAY("content", contentPaths, addContentPath, QWebContentPath)
};

#endif // QWEBMODULE_H
