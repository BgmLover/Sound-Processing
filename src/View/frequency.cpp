#include "frequency.h"
#include "ui_frequency.h"
#include<QDebug>
Frequency::Frequency(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frequency)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setValue(1.0);
    nowValue=ui->doubleSpinBox->value();
}

Frequency::~Frequency()
{
    delete ui;
}

void Frequency::on_buttonBox_accepted()
{
      qDebug()<<"频率设置对话框信号发射";
      frequency=ui->doubleSpinBox->value();
      emit(frequencyReturn(frequency));
      nowValue=frequency;

}

void Frequency::on_buttonBox_rejected()
{
     ui->doubleSpinBox->setValue(nowValue);
}
