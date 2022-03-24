#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <string>

size_t passHash(std::string input) {
    std::hash<std::string> inputHash;
    return inputHash(input);
}
