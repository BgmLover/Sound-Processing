#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QDialog>

namespace Ui {
class Frequency;
}

class Frequency : public QDialog
{
    Q_OBJECT

public:
    explicit Frequency(QWidget *parent = 0);
    ~Frequency();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Frequency *ui;
    double frequency;
    double nowValue;
signals:
    void frequencyReturn(double);
};

#endif // FREQUENCY_H
