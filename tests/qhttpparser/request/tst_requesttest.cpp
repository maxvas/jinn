#include <QString>
#include <QtTest>
#include <qhttpparser.h>

class RequestTest : public QObject
{
    Q_OBJECT

public:
    RequestTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();
};

RequestTest::RequestTest()
{
}

void RequestTest::initTestCase()
{
}

void RequestTest::cleanupTestCase()
{
}

void RequestTest::testCase1()
{
    QFETCH(QString, data);
    QHttpParser p;
    p.putData();
    QVERIFY2(true, "Failure");
}

void RequestTest::testCase1_data()
{
    QTest::addColumn<QByteArray>("data");
    QTest::newRow("0") << QString();
}

QTEST_APPLESS_MAIN(RequestTest)

#include "tst_requesttest.moc"
