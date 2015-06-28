#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include<QPushButton>
#include <QTimer>
#include <QLCDNumber>
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
    void operator-(Block * a);
    void operator|(Block * a);
    QTimer *t;
public slots:
    void click();
    void right();
    void left();
    void down();
    void up();
signals:
        void Click(int R,int C);
        void Alter();
private:
        int shift;
};

#endif // BLOCK_H
