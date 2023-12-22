#ifndef LIST_LIST_H
#define LIST_LIST_H
using namespace std;
class List {
private:
    struct node{
        string data;
        node* next;
        //node* pre;
    };
    node* head;
    unsigned int length;
public:
    List();
    List(const char&);
    List(const string&);
    List(const List&);
    //void append();
    void append(const string&);
    void append(const char&);
    void insert(const string&);
    void insert(const char&);
    void insert(const int&,const string&);
    //void insert(const int&,const char&);
    string pick();
    string pickFromDown();
    string pwi(const int&) const;
    string pop();
    string pfd();
    //string pop(const int&);
    //void del(const string&);
    //void del(const char&);
    //void removeDuplicate();
    //void removeDuplicate(const string&);
    //void removeDuplicate(const char&);
    //List operator+(const List&);
    //List operator+(const string&);
    //List operator+(const char&);
    //List operator-(const List&);
    //List operator-(const string&);
    //List operator-(const char&);
    List& operator=(const List&);
    //List operator=(const string&);
    //List operator=(const char&);
    unsigned int getLengths() const;
    bool isEmpty() const;
    //bool in(const string&);
    //bool in(const char&);
    void print() const;
};


#endif //LIST_LIST_H
