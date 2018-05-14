#include<iostream>
#include<map>
#include<cstring>
#ifndef User_H
#define User_H
#include"User.h"
#endif
#ifndef Book_H
#define Book_H
#include"Book.h"
#endif
#ifndef User_management_H
#define User_management_H
#include"User_management.h"
#endif
#ifndef Book_Database_H
#define Book_Database_H
#include"Book_Database.h"
#endif
#ifndef Paper_H
#define Paper_H
#include"Paper.h"
#endif
using namespace std;
#include<map>
extern map<int,int>USER;
extern map<int,int>BOOK;
extern int user_sum;
extern int book_sum;
extern User User_[300];
extern Book Book_[2000];
int main()
{
    int choice;
    int reader_ID;
    int book_ID;
    Book book;
    User reader;
    reader.in();
    book.in();
    User_management User_data;
    cout<<"--图书管理系统--"<<endl;
    cout<<"1 新用户注册"<<endl;
    cout<<"2 用户登录"<<endl;
    cout<<"3 管理员登录"<<endl;
    cout<<"4 退出"<<endl;
    char name[5]={0};
    cin>>choice;
    char password[20]={0};
    int ID;
    while (choice!=4)
    {
        switch (choice)
        {
            case 1:
                cout << "请输入您的姓名:" << endl;
                cin >> name;
                cout << "请输入您的学号ID:" << endl;
                cin >> ID;
                cout << "请输入您的密码:" << endl;
                cin >> password;
                if (User_data.add_user(ID,name,password)==0)
                {
                    cout<<"该用户已存在!"<<endl;
                }
                else
                {
                    //reader.add_user(ID,name,password);
                    USER[ID]=user_sum;
                    //strcpy(User_[user_sum].Name,name);
                    //User_[user_sum].User_ID=id;
                    //strcpy(User_[user_sum].Password,password);
                    //user_sum++;
                    cout << "注册成功" << endl;

                }
                //User_data.set_User_role(ID, name, password);
                break;
            case 2:
                cout << "请输入您的姓名:" << endl;
                cin >> name;
                cout << "请输入您的学号ID:" << endl;
                cin >> ID;
                if (USER.count(ID) == 0)
                {
                    cout << "读者信息输入有误" << endl;
                }
                else
                {
                    cout << "请输入您的密码:" << endl;
                    cin >> password;
                    if (strcmp(User_[USER[ID]].get_Password(), password) == 0)
                    {
                        cout << "登录成功！" << endl;
                        reader.menu();
                    }
                    else
                    {
                        cout << "输入密码错误！" << endl;
                    }
                }
                break;
            case 3:
                break;
            case 4:
                return 0;
                
        }
        cout<<endl;
        cout<<"--返回主菜单？--"<<endl;
        cout<<"1 是"<<endl;
        cout<<"0 直接退出"<<endl;
        int option;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"--图书管理系统--"<<endl;
                cout<<"1 新用户注册"<<endl;
                cout<<"2 用户登录"<<endl;
                cout<<"3 管理员登录"<<endl;
                cout<<"4 退出"<<endl;
                break;
            case 0:
                return 0;
        }
        cin>>choice;
        cout<<endl;
    }
    return 0;
}
