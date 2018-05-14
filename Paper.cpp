
#ifndef Paper_H
#define Paper_H
#include"Paper.h"
#endif

#include<iostream>
using namespace std;
#include<cstring>

void Paper::add_Paper(int num,char *name, char *publication,char *time,char *position,char *electronic_sourse)
{
    Num=num;
    strcpy(Name,name);
    strcpy(Publication,publication);
    strcpy(Time,time);
    strcpy(Position,position);
    strcpy(Electronic_sourse,electronic_sourse);
    freopen("Paper.Num.txt","w",stdout);
    //cout<<Electronic_sourse<<endl;
}
