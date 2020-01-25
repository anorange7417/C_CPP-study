#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *title;
    char *isbn;
    int price;

public:
    Book(char *mytitle, char *myisbn, int myprice)
    {
        title = new char[strlen(mytitle) + 1]; // char형 pointer인 title에 heap영역의 char형 주소 할당
        strcpy(title, mytitle);                // title에 mytitle 내용을 씀
        isbn = new char[strlen(myisbn) + 1];
        strcpy(isbn, myisbn);
        price = myprice;
    }
    void ShowBookInfo()
    {
        cout << "title : " << title << endl; // *title 출력은?
        cout << "ISBN : " << isbn << endl;
        cout << "Price : " << price << endl;
    }
    ~Book()
    {
        delete title;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;

public:
    EBook(char *mytitle, char *myisbn, int myprice, char *myDRMKey)
        : Book(mytitle, myisbn, myprice), DRMKey(myDRMKey) {}
    void ShowEbookInfo()
    {
        ShowBookInfo();
        cout << "Serial Number: " << DRMKey << endl;
    }
};

int main()
{
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("Good C++", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEbookInfo();
    return 0;
}