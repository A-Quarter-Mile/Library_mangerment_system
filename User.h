#ifndef Book_H
#define Book_H
#include"Book.h"
#endif
using namespace std;
#include<cstring>
const int Borrow_book_maximun=10;
extern Book Book_[2000];
class User             //读者类
{
public:
    User()
    {
        memset(Name,0,10);
        User_ID=0;
        memset(Password,0,10);
        Borrow_sum=0;
        memset(Borrow_book,0,Borrow_book_maximun);
        
    }
    char *get_Name()
    {
        return Name;
    }
    int get_User_ID()
    {
        return User_ID;
    }
    char *get_Password()
    {
        return Password;
    }
    void Borrow(int Book_ID);
    void Back(int Book_ID);
    void Show_borrow_book(int Book_ID);
    void add_User(int ID, char *name, char *password);
    void update(char *new_password);
    void menu();
    void in();
    ~User(){};
    
private:
    char Name[10];
    int User_ID;
    char Password[10];
    int Borrow_sum;
    int  Borrow_book[Borrow_book_maximun];
};
