#ifndef __Reader_H__
#define __Reader_H__
#include"Book.h"
#include<set>
#include<string>

class Reader
{
private:
    int uid;
    char name[101];
    std::set<int> record;
public:
    Reader();
    Reader(std::string ss);
    ~Reader();
    char* get_name();
    void PrintInfo();
    void Borrow_book(Book b);
    void Return_book(Book b);
    std::set<int> Print_record();
    int get_uid(){return uid;};
    void set_uid(int d){uid=d;};
};

 
#endif