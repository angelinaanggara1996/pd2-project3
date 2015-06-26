#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include<QPushButton>
class Block : public QObject
{
        Q_OBJECT
public:
    explicit Block(QWidget *parent, int R, int C);
    ~Block();
    QPushButton *button;
    const int row;
    const int column;
    int number;
    void setButtonPicture();
    void setRandomNumber();
public slots:
    void click();
signals:
        void Click(int R,int C);
};

#endif // BLOCK_H
