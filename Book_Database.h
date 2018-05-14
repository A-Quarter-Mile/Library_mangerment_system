
using namespace std;
class Book_Database
{
public:
    Book_Database();
    void BD_add(int num,int ISBN,char *Name,char *Writer,char *Publication,char *time);
    void BD_update();
    void BD_delete(Book *book);
    void BD_view(Book *book);
    void BD_search();
    ~Book_Database(){};
private:
    
};
