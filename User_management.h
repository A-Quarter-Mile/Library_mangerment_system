#ifndef User_H
#define User_H
#include"User.h"
#endif
using namespace std;
const int User_sum_maximun=10000;
class User_management      //读者管理类
{
public:
    User_management()
    {
        User_sum=0;
    }
    int add_user(int ID, char *name, char *password);
    int update_User(int ID,char *old_password,char *new_password);
    void delete_User();
    void set_User_role(int ID, char *name, char *password);
    ~User_management(){};
private:
    User user[User_sum_maximun];
    int User_sum;
    
};
