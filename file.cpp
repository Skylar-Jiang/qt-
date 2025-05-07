#include "file.h"
#include <QTextStream>

File::File()
{
    QFile file("/Users/apple/Desktop/plantVSzombie/txt/maxscore.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        score = file.readAll();
        if(score == "")
            score = QString::number(0, 10);
        qDebug() << score;
        file.close();
    }

}
int File::getMaxScore()
{
    return score.toInt();
}
void File::writeScore(int _score)
{
    QFile file("/Users/apple/Desktop/plantVSzombie/txt/maxscore.txt");
    if( _score > score.toInt())
    {
        qDebug() << "yes";
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream txtOutput(&file);
            txtOutput << QString::number(_score, 10);
            file.close();
        }
    }
}
