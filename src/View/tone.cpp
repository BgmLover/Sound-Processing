#include "tone.h"
#include "ui_tone.h"
#include<QDebug>
Tone::Tone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tone)
{
    ui->setupUi(this);
    ui->horizontalSlider->setRange(0,35);
    ui->horizontalSlider->setValue(21);
    nowValue=ui->horizontalSlider->value();
}

Tone::~Tone()
{
    delete ui;
}

void Tone::on_buttonBox_accepted()
{
    qDebug()<<"音调设置对话框信号发射";

    emit toneReturn(tone);
    nowValue=ui->horizontalSlider->value();
}

void Tone::on_buttonBox_rejected()
{
    ui->horizontalSlider->setValue(nowValue);
}

void Tone::on_horizontalSlider_valueChanged(int value)
{
    if(value==0)
        tone="C5";
    if(value==1)
        tone="C#5";
    if(value==2)
        tone="D5";
    if(value==3)
        tone="D#5";
    if(value==4)
        tone="E5";
    if(value==5)
        tone="F5";
    if(value==6)
        tone="F#5";
    if(value==7)
        tone="G5";
    if(value==8)
        tone="G#5";
    if(value==9)
        tone="A5";
    if(value==10)
        tone="A#5";
    if(value==11)
        tone="B5";
    if(value==12)
        tone="C6";
    if(value==13)
        tone="C#6";
    if(value==14)
        tone="D6";
    if(value==15)
        tone="D#6";
    if(value==16)
        tone="E6";
    if(value==17)
        tone="F6";
    if(value==18)
        tone="F#6";
    if(value==19)
        tone="G6";
    if(value==20)
        tone="G#6";
    if(value==21)
        tone="A6";
    if(value==22)
        tone="A#6";
    if(value==23)
        tone="B6";
    if(value==24)
        tone="C7";
    if(value==25)
        tone="C#7";
    if(value==26)
        tone="D7";
    if(value==27)
        tone="D#7";
    if(value==28)
        tone="E7";
    if(value==29)
        tone="F7";
    if(value==30)
        tone="F#7";
    if(value==31)
        tone="G7";
    if(value==32)
        tone="G#7";
    if(value==33)
        tone="A7";
    if(value==34)
        tone="A#7";
    if(value==35)
        tone="B5";
    ui->ToneValue->setText(tone);
}




