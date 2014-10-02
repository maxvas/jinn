#ifndef QWEBCONTENTPATH_H
#define QWEBCONTENTPATH_H

#include <QJSMapping>

class QWebContentPath : public QJSMapping
{
public:
    QJS_MAPPING_QSTRING("url", url, setUrl)
    QJS_MAPPING_QSTRING("path", path, setPath)

};

#endif // QWEBCONTENTPATH_H
