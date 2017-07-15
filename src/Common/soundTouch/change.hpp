#pragma once
#ifndef CHANGE_H
#define CHANGE_H

#include <stdio.h>
#include <string.h>
#include <vector>
#include<QString>
using namespace std;


void InitToneMap();
int change();
QString change_once(const string &filestress,const string &a, const double b);
QString change_more(const string &filestress,const vector<string>&a,const vector<double> &b);


#endif
