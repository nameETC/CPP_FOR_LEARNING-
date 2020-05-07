#ifndef __Manager_H__
#define __Manager_H__

#include"Book.h"
#include"Reader.h"

class Manager
{
private:
    int bs,br;
    Book books[10001];
    Reader readers[10001];
public:
    Manager();
    ~Manager();
    void AddBook(Book b);
    void AddReader(Reader &r);
    void DeleteBook(Book ob);
    void DeleteReader(Reader &r);
    void BorrowBook(Reader r,Book b);
    void ReturnBook(Reader r,Book b);
    void PrintBookRemaining();
    void PrintBookBorrowed();
    void PrintReaderRec(Reader r);
    void List_Reader_and_borrowed_books(Reader r);
    void Print_All_readers();
    void Print_All_Books_And_States();
    Book Get_bookInfo(int bid);
    int Get_book_remain(int id);
};
 
#endif
