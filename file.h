#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QFileInfo>
#include <QDebug>

class File
{
public:
    File();
    int getMaxScore();
    QString score;
    void writeScore(int _score);
};

#endif // FILE_H
