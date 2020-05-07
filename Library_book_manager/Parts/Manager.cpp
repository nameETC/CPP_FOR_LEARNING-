#include"Book.h"
#include"Reader.h"
#include"Manager.h"
#include<cstring>
#include<cstdio>
#include<set>

const int MAXBOOK=10001;

Manager::Manager(){
    bs=br=0;
    for(int i=0;i<10001;++i){
        books[i].set_state(-1);
        readers[i].set_uid(-1);
    }
}

Manager::~Manager(){}

void Manager::AddBook(Book b){
    b.set_id(bs);b.set_state(1);
    books[bs++]=b;
}


void Manager::DeleteBook(Book b){
    books[b.get_id()].set_state(-1);
}


void Manager::AddReader(Reader &r){
    r.set_uid(br);
    readers[br++]=r;
}


void Manager::DeleteReader(Reader &r){
    readers[r.get_uid()].set_uid(-1);
}

void Manager::BorrowBook(Reader r,Book b){
    if(b.get_state()==-1){
        printf("We don't have the book.\n");
        return ;
    }
    if(books[b.get_id()].get_state()==1){
        readers[r.get_uid()].Borrow_book(b);
        books[b.get_id()].set_state(0);
        books[b.get_id()].set_reader(r.get_uid());
    }
    else if(books[b.get_id()].get_state()==0){
        printf("The book \"%s\" has already borrowed by %s!\n",books[b.get_id()].get_name(),readers[books[b.get_id()].get_reader()].get_name());
    } 
    else{
        printf("We don't have the book.\n");
    }
}

void Manager::ReturnBook(Reader r,Book b){
    readers[r.get_uid()].Return_book(b);
    books[b.get_id()].set_state(1);
}

void Manager::PrintBookBorrowed(){
    printf("***Borrowed books:***\n");
    for(int i=0;i<bs;++i){
        if(books[i].get_state()==0){
            printf("%s\n",books[i].get_name());
        }
    }
    printf("*********************\n");
}

void Manager::PrintBookRemaining(){
    printf("***Remining Books:***\n");
    for(int i=0;i<bs;++i){
        if(books[i].get_state()==1){
            printf("%s\n",books[i].get_name());
        }
    }
    printf("*********************\n");
}

void Manager::PrintReaderRec(Reader r){
    std::set<int> temp=r.Print_record();
    for(auto iter=temp.begin();iter!=temp.end();++iter){
        r.PrintInfo();
        printf(" has borrowed %s\n",books[*iter].get_name());
    }
}

Book Manager::Get_bookInfo(int bid){
    if(bid>=bs){printf("Illeagal operation!\n");return books[bid];}
    else return books[bid];
}

void Manager::List_Reader_and_borrowed_books(Reader r){
    printf("******************\n");
    readers[r.get_uid()].PrintInfo();
    std::set<int> ts=readers[r.get_uid()].Print_record();
    for(auto iter=ts.begin();iter!=ts.end();++iter){
        printf("%s\n",books[*iter].get_name());
    }
    printf("******************\n");
}
void Manager::Print_All_readers(){
    printf("Reader's Info:\n");
    for(int i=0;i<br;++i){
        if(readers[i].get_uid()!=-1){
            readers[i].PrintInfo();
        }
    }
    printf("END\n");
}

void Manager::Print_All_Books_And_States(){
    printf("------------------\n");
    for(int i=0;i<bs;++i){
        if(books[i].get_state()!=-1){
            printf("Book: \"%s\" State:%s\n",books[i].get_name(),books[i].get_state()==1?"In Library":"Borrowed");
        }
    }
    printf("-------------------\n");
}