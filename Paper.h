#include<cstring>
using namespace std;
class Paper
{
public:
    Paper()
    {
        Num=0;
        memset(Name,0,10);
        memset(Publication,0,20);
        memset(Position,0,20);
        memset(Electronic_sourse,0,50);
    }
    int get_Num()
    {
        return Num;
    }
    char *get_Name()
    {
        return Name;
    }
    char *get_Time()
    {
        return Time;
    }
    char *get_Position()
    {
        return Position;
    }
    char *get_Publication()
    {
        return Publication;
    }
    char *get_Electronic_sourse()
    {
        return Electronic_sourse;
    }
    void add_Paper(int num,char *name, char *publication,char *time,char *position,char *electronic_sourse);
    ~Paper(){};
private:
    int Num;
    char Name[10];
    char Publication[20];
    char Time[20];
    char Position[20];
    char Electronic_sourse[50];
};
