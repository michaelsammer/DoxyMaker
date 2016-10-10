#ifndef ANALYSER_H
#define ANALYSER_H

#include <QString>
#include <QStringList>

class Analyser
{
public:
    Analyser();

private:

    QStringList getRows(QString input);
};

#endif // ANALYSER_H
