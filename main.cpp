#include <QCoreApplication>

#include "Parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Parser parser;
    return a.exec();
}
