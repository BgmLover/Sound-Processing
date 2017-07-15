#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include "WavFile.h"
#include "SoundTouch.h"
#include "BPMDetect.h"
#include <iostream>
#include <algorithm>
#include "STTypes.h"
#include <vector>
#include <sstream>
#include <map>
//#include <windows.h>
#include <vector>
#include<QString>
#include<QStringList>
#include<QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include<QObject>
#include<QUrl>
using namespace soundtouch;
using namespace std;
#define BUFF_SIZE           6720
map<string, int> tonemap;
template<class T>
string tostring(T& x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}
void InitToneMap()
{
    string keys[] = { "C","C#","D","D#","E","F","F#","G","G#","A","A#","B" };
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j<12; j++)
            tonemap[keys[j] + tostring(i)] = i * 12 + j - 82;
    }
}
void WriteVoidSample(WavOutFile* wavout, SoundTouch* pSoundTouch, int num, int channels, double tempo)
{
    short *sampleBuffer = new short[num];
    memset(sampleBuffer, 0, sizeof(short)*num);
    pSoundTouch->setTempo(tempo);
    pSoundTouch->putSamples(sampleBuffer, num / channels);
    pSoundTouch->receiveSamples(sampleBuffer, num);
    wavout->write(sampleBuffer, num);
    delete[]sampleBuffer;
}
void WriteProcessSample(WavInFile* wavin, WavOutFile* wavout, SoundTouch* pSoundTouch, int tone, double tempo)
{
    int nSamples;
    int nChannels;
    int buffSizeSamples;
    short *sampleBuffer = new short[BUFF_SIZE];
    pSoundTouch->setPitchSemiTones(tone);
    pSoundTouch->setTempo(tempo);
    while (!wavin->eof())
    {
        int num;
        num = wavin->read(sampleBuffer, BUFF_SIZE);
        nSamples = num / (int)wavin->getNumChannels();
        nChannels = (int)wavin->getNumChannels();
        buffSizeSamples = BUFF_SIZE / nChannels;
        pSoundTouch->putSamples(sampleBuffer, nSamples);
        do
        {
            nSamples = pSoundTouch->receiveSamples(sampleBuffer, buffSizeSamples);
            wavout->write(sampleBuffer, nSamples * nChannels);
        } while (nSamples != 0);
    }
    wavin->rewind();
    pSoundTouch->clear();
    delete[]sampleBuffer;
}
//int change()
//{
//    FILE* fp = fopen("tone.txt", "r");
//    if (fp)
//    {
//        WavInFile *wavin;
//        WavOutFile *wavout;
//        SoundTouch *pSoundTouch;
//        wavin = new WavInFile("fa.wav");
//        pSoundTouch = new SoundTouch;
//        pSoundTouch->setSampleRate(wavin->getSampleRate());
//        pSoundTouch->setChannels(wavin->getNumChannels());
//        wavout = new WavOutFile("out.wav", wavin->getSampleRate(), wavin->getNumBits(), wavin->getNumChannels());
//        InitToneMap();
//        char tone[4];
//        double meter;
//        while (~fscanf(fp, "%s%lf", tone, &meter))
//        {
//            printf("%s", tone);
//            getchar();
//            if (tone[0] != '0')
//                WriteProcessSample(wavin, wavout, pSoundTouch, tonemap[tone], 1 / meter);
//            else
//                WriteVoidSample(wavout, pSoundTouch, wavin->getDataSizeInBytes(), wavin->getNumChannels(), 1 / meter);
//        }
//        delete wavin;
//        delete wavout;
//        delete pSoundTouch;
//    }
//    return 0;
//}
QString change_once(const string &filestress,const string &a, const double b) {
    int i,j;
    WavInFile *wavin;
    WavOutFile *wavout;
    SoundTouch *pSoundTouch;
    wavin = new WavInFile(filestress.c_str());
    pSoundTouch = new SoundTouch;
    pSoundTouch->setSampleRate(wavin->getSampleRate());
    pSoundTouch->setChannels(wavin->getNumChannels());
    QString initialName=QDir::homePath();
    //qDebug()<<"1";
    QString path =QFileDialog::getSaveFileName(nullptr, QObject::tr("选择文件"), initialName,QObject::tr("*.wav"));

    /*qDebug()<<"2";
    QString name;
    name=name.fromStdString(filestress);
    name=name.split("\\").last();
    name="output"+name;
    name="F:\\QTpractice\\MiniAudio\\MiniAudio\\OutPutWaves/"+name;*/
    qDebug()<<path;
    string n=path.toStdString();
    const char *s=n.c_str();
   // addr="OutPutWaves/"+"D:\CloudMusic/out3.wav"
    wavout = new WavOutFile(s, wavin->getSampleRate(), wavin->getNumBits(), wavin->getNumChannels());
    InitToneMap();
    string tone = a;
    j = a.size();
    tone[j] = '\0';

    double meter;

    meter = b;
    if (tone[0] != '0')
        WriteProcessSample(wavin, wavout, pSoundTouch, tonemap[tone], 1 / meter);
    else
        WriteVoidSample(wavout, pSoundTouch, wavin->getDataSizeInBytes(), wavin->getNumChannels(), 1 / meter);
    delete wavin;
    delete wavout;
    delete pSoundTouch;
    return path;
}
void change_more(const string &filestress,const vector<string>&a,const vector<double> &b) {
    int i,c,j,h;
    c = a.size();
    WavInFile *wavin;
    WavOutFile *wavout;
    SoundTouch *pSoundTouch;
    wavin = new WavInFile(filestress.c_str());
    pSoundTouch = new SoundTouch;
    pSoundTouch->setSampleRate(wavin->getSampleRate());
    pSoundTouch->setChannels(wavin->getNumChannels());
    wavout = new WavOutFile("D:\CloudMusic/out3.wav", wavin->getSampleRate(), wavin->getNumBits(), wavin->getNumChannels());
    InitToneMap();
    char tone[4];
    double meter;

    for (i = 0; i < c; i++) {
        h = (int)a[i].size();
        strncpy(tone, a[i].c_str(), h);
        
        tone[h] = '\0';
        printf("%s", tone);

        meter = b[i];
        if (tone[0] != '0')
            WriteProcessSample(wavin, wavout, pSoundTouch, tonemap[tone], 1 / meter);
        else
            WriteVoidSample(wavout, pSoundTouch, wavin->getDataSizeInBytes(), wavin->getNumChannels(), 1 / meter);
    }
    delete wavin;
    delete wavout;
    delete pSoundTouch;
}
