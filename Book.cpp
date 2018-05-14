#ifndef Book_H
#define Book_H
#include"Book.h"
#endif
#include<iostream>
#include<map>
using namespace std;
extern map<int,int>BOOK;
Book Book_[2000];
void Book::Book_delete(Book *book)     //删除图书
{
    delete book;
    book=0;
}
void Book::Display_Situation()    //图书状态展示
{
    if (get_Situation()==0)
    {
        cout<<"在库"<<endl;
        return;
    }
    if (get_Situation()==1)
    {
        cout<<"在借"<<endl;
        return;
    }
    if (get_Situation()==2)
    {
        cout<<"异常"<<endl;
        return;
    }
}
void Book::Display_Position()    //展示图书位置
{
    int i,l=strlen(Position);
    for (i=0;i<=l;i++)
    {
        cout<<Position[i-1];
    }
}
void Book::add_Book(int num,long long isbn,char *name,char *writer,char *publication,char *time)
{
    Num=num;
    ISBN=isbn;
    strcpy(Name,name);
    strcpy(Writer,writer);
    strcpy(Publication,publication);
    strcpy(Time,time);
    return;
}
int Book::Book_borrow()
{
    if (get_Situation()==0)
    {
        Situation=1;
        return 1;
    }
    return 0;
}
int Book::Book_back()
{
    if (get_Situation()==1)
    {
        Situation=0;
        return 1;
    }
    return 0;
}
void Book::in()
{
    FILE* Book_input=fopen("Book.in","r");
    book_sum=1;
    while (fscanf(Book_input,"%s%d%lld%s%s%s",Book_[book_sum].Name,&Book_[book_sum].Num,&Book_[book_sum].ISBN,Book_[book_sum].Writer,Book_[book_sum].Publication,Book_[book_sum].Time)!=EOF)
    {
        BOOK[Book_[book_sum].Num]=book_sum;
        ++book_sum;
    }
}
