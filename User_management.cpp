#ifndef User_H
#define User_H
#include"User.h"
#endif
#ifndef User_management_H
#define User_management_H
#include"User_management.h"
#endif
#include<iostream>
#include<map>
using namespace std;
extern map<int,int>USER;
extern map<int,int>BOOK;
extern int user_sum;
extern int book_sum;
extern User User_[200];
extern Book Book_[2000];
int User_management::add_user(int ID, char *name, char *password)   //判断读者是否存在
{
    if (USER.count(ID)==0)
    {
        User_sum++;
        set_User_role(ID,name,password);
        return 1;
    }
    else
        return 0;
}
int User_management::update_User(int ID,char *old_password,char *new_password)  //更新用户数据(密码）
{
    User user;
    if (USER.count(ID)==0)
        return 0;
    else
    {
        user=User_[USER[ID]];
        if (user.get_Password()==old_password)
        {
            user.update(new_password);
        }
    }
    return 0;
};
void User_management::set_User_role(int ID, char *name, char *password)   //增加新用户
{
    user_sum++;
    User user[user_sum];
    user[user_sum].add_User(ID,name,password);
    USER[ID]=user_sum;
};
void User_management::delete_User()
{
    
}

