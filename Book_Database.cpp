
#ifndef Book_H
#define Book_H
#include"Book.h"
#endif
#ifndef Book_Database_H
#define Book_Database_H
#include"Book_Database.h"
#endif
#include<iostream>
#include<map>
using namespace std;
extern map<int,int>USER;
extern map<int,int>BOOK;
extern int user_sum;
extern int book_sum;
extern Book Book_[2000];
void Book_Database::BD_add(int num,int ISBN,char *Name,char *Writer,char *Publication,char *time)
{
    if (BOOK.count(num)==0)
    {
        book_sum++;
        Book_[book_sum].add_Book(num,ISBN,Name,Writer,Publication,time);     //add
    }
    
}
void Book_Database::BD_delete(Book *book)
{
    book->Book_delete(book);
    return;
}
void Book_Database::BD_view(Book *book)
{
    book->Display_Position();
    book->Display_Situation();
    return;
}
void Book_Database::BD_search()    //查找何种信息
{
    Book book;
    int book_ID;
    cout<<"请输入查找图书的ID："<<endl;
    cin>>book_ID;
    cout<<"1 书名"<<endl;
    cout<<"2 作者"<<endl;
    int choice;
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<book.get_Name()<<endl;
            break;
        case 2:
            cout<<book.get_Writer()<<endl;
            break;
    }
}
