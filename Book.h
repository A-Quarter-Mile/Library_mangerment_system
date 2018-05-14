using namespace std;
#include<cstring>
extern int book_sum;

class Book     //图书类
{
public:
    Book()
    {
        Num=0;
        ISBN=0;
        memset(Name,0,20);
        memset(Writer,0,10);
        memset(Publication,0,20);
        memset(Time,0,20);
        Situation=0;
        memset(Position,0,50);
        electronic=0;
    }
    int get_Num()
    {
        return Num;
    }
    char *get_Name()
    {
        return Name;
    }
    char *get_Writer()
    {
        return Writer;
    }
    char *get_Publication()
    {
        return Publication;
    }
    int get_Situation()
    {
        return Situation;
    }
    long long get_ISBN()
    {
        return ISBN;
    }
    char *get_Time()
    {
        return Time;
    }
    void Display_Situation();
    void Display_Position();
    void add_Book(int num,long long isbn,char *name,char *writer,char *publication,char *time);
    int get_electronic()
    {
        return electronic;
    }
    int Book_borrow();
    int Book_back();
    void Book_delete(Book *book);
    void in();
    ~Book(){};
private:
    int Num;
    long long ISBN;
    char Name[20];
    char Writer[10];
    char Publication[20];
    char Time[20];
    int Situation;
    char Position[50];
    int electronic;
};

