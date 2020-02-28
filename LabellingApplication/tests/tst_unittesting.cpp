#include <QtTest>

// add necessary includes here

class UnitTesting : public QObject
{
    Q_OBJECT

public:
    UnitTesting();
    ~UnitTesting();

private slots:
    void test_case1();

};

UnitTesting::UnitTesting()
{

}

UnitTesting::~UnitTesting()
{

}

void UnitTesting::test_case1()
{

}

QTEST_APPLESS_MAIN(UnitTesting)

#include "tst_unittesting.moc"
