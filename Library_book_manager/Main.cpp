#include"./Parts/Book.h"
#include"./Parts/Reader.h"
#include"./Parts/Manager.h"
#include<cstdio>
#include<string>

int main(){
    Manager mach1;
    Book b("Good_Manner");
    Book b2("Collapse");
    Book b3("Military");
    Book b4("New_Life");
    Book b5("nameETC's Profile");
    Book b6("三国志");

    mach1.AddBook(b);mach1.AddBook(b2);mach1.AddBook(b3);mach1.AddBook(b4);
    mach1.AddBook(b5),mach1.AddBook(b6);
    
    
    
    mach1.PrintBookRemaining();//1
    std::string s;
    s="ZhangSan";Reader r1(s);
    s="LiSi";Reader r2(s);
    s="John";Reader r3(s);
    s="Machiell_Simth";Reader r4(s);

    //Add Reader operations
    //begin
    mach1.AddReader(r1),mach1.AddReader(r2),mach1.AddReader(r3),mach1.AddReader(r4);
    //end

    //Borrow or Return Books
    //begin
    mach1.BorrowBook(r1,mach1.Get_bookInfo(1));
    mach1.BorrowBook(r4,mach1.Get_bookInfo(2));
    mach1.BorrowBook(r3,mach1.Get_bookInfo(1));
    mach1.BorrowBook(r4,mach1.Get_bookInfo(5));
    mach1.BorrowBook(r4,mach1.Get_bookInfo(7));
    //end

    /*test*/
    //mach1.PrintBookRemaining();
    //mach1.PrintBookBorrowed();
    mach1.Print_All_readers();
    mach1.DeleteReader(r3);
    mach1.Print_All_readers();
    mach1.Print_All_Books_And_States();
    /*test*/

    mach1.List_Reader_and_borrowed_books(r1);mach1.List_Reader_and_borrowed_books(r4);
    mach1.List_Reader_and_borrowed_books(r2);
    mach1.ReturnBook(r1,mach1.Get_bookInfo(1));
    mach1.ReturnBook(r4,mach1.Get_bookInfo(5));
    mach1.PrintBookRemaining();//4
    return 0;

}