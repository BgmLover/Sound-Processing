#ifndef TONE_H
#define TONE_H

#include <QDialog>
#include<QString>
namespace Ui {
class Tone;
}

class Tone : public QDialog
{
    Q_OBJECT

public:
    explicit Tone(QWidget *parent = 0);
    ~Tone();

private slots:
    void on_buttonBox_accepted();

    void on_horizontalSlider_valueChanged(int value);

    void on_buttonBox_rejected();

private:
    Ui::Tone *ui;
    QString tone;
    int nowValue;
signals:
    void toneReturn(QString);
};

#endif // TONE_H
