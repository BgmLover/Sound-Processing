#pragma once
#ifndef CHANGE_H
#define CHANGE_H

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;


void InitToneMap();
int change();
void change_once(const string &filestress,const string &a, const double b);
void change_more(const string &filestress,const vector<string>&a,const vector<double> &b);


#endif
