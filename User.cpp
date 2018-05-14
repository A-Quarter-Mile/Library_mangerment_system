#ifndef Book_H
#define Book_H
#include"Book.h"
#endif
#ifndef User_H
#define User_H
#include"User.h"
#endif
#include<iostream>
#include<map>
using namespace std;
extern map<int,int>USER;
extern map<int,int>BOOK;
extern int user_sum;
extern int book_sum;
User User_[200];
extern Book Book_[2000];
void User::Borrow(int Book_ID)     //借书
{
    int i;
    for (i=1;i<=Borrow_sum;i++)
    {
        if (Borrow_book[i]==0)
        {
            Borrow_book[i]=Book_ID;
            Borrow_sum++;
            return;
        }
    }
}
void User::Back(int Book_ID)     //还书
{
    int i;
    for (i=0;i<=Borrow_sum;i++)
    {
        if (Borrow_book[i]==Book_ID)
        {
            Borrow_book[i]=0;
            Borrow_sum--;
            return;
        }
    }
}
void User::Show_borrow_book(int Book_ID)    //输出本次借书
{
    int i;
    for (i=0;i<=9;i++)
    {
        if (Name[i]!=0)
            cout<<Name[i];
        else
            break;
    }
    cout<<"本次借书为：";
    char bookname[20]={0};
    strcpy(bookname,Book_[BOOK[Book_ID]].get_Name());
    int l=strlen(bookname);
    for (i=0;i<=l;i++)
    {
        cout<<bookname[i];
    }
    cout<<endl;
    //cout<<"请在此日期前还书：";
}
void User::update(char *new_password)      //重置密码
{
    memset(Password,0,10);
    strcpy(Password,new_password);
}
void User::add_User(int id, char *name, char *password)    //增加读者用户
{
    
    return;
}
void User::menu()
{
    cout<<"--用户界面--"<<endl;
    cout<<"1 借书"<<endl;
    cout<<"2 还书"<<endl;
    cout<<"3 图书查询"<<endl;
    cout<<"4 修改密码"<<endl;
    cout<<"5 退出"<<endl;
    int option;
    int book_ID;
    cin>>option;
    switch (option)
    {
        case 1:
            cout<<"请输入您借阅的图书编号："<<endl;
            cin>>book_ID;
            if (BOOK.count(book_ID)==0)
            {
                cout<<"输入图书不存在"<<endl;
                break;
            }
            else
            {
                Book &book=Book_[BOOK[book_ID]];
                switch (book.get_Situation())
                {
                    case 1:
                        cout<<"图书已借出"<<endl;
                        break;
                    case 2:
                        cout<<"当前图书存在异常"<<endl;
                        break;
                    case 0:
                        book.Book_borrow();
                        Borrow(book.get_Num());
                        Show_borrow_book(book_ID);
                        break;
                }
            }
            break;
        case 2:
            cout<<"请输入您归还的图书编号："<<endl;
            cin>>book_ID;
            if (BOOK.count(book_ID)==0)
            {
                cout<<"输入图书不存在"<<endl;
                break;
            }
            else
            {
                Book &book=Book_[BOOK[book_ID]];
                book.Book_back();
                Back(book.get_Num());
                cout<<"归还成功！"<<endl;
            }
            break;
        case 3:
            cout<<"请输入您查询的图书编号："<<endl;
            cin>>book_ID;
            if (BOOK.count(book_ID)==0)
            {
                cout<<"输入图书不存在"<<endl;
                break;
            }
            else
            {
                Book &book=Book_[BOOK[book_ID]];
                book.Display_Situation();
            }
            break;
        case 4:{
            char new_password_[20]={0};
            cout<<"请输入新密码："<<endl;
            cin>>new_password_;
            update(new_password_);
            cout<<"修改密码成功！"<<endl;
            break;
        }
        case 5:
            return;
    }
    this->menu();
}
void User::in()
{
    FILE* User_input=fopen("User.in","r");
    user_sum=1;
    while (fscanf(User_input,"%s%d%s",User_[user_sum].Name,&User_[user_sum].User_ID,User_[user_sum].Password)!=EOF)
    {
        USER[User_[user_sum].User_ID]=user_sum;
        ++user_sum;
    }
}



