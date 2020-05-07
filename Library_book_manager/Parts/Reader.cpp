#include"Book.h"
#include"Reader.h"
#include<cstdio>
#include<string>

Reader::Reader(){}
Reader::Reader(std::string ss)
{
    memcpy(this->name,ss.c_str(),sizeof(this->name));
}

Reader::~Reader()
{
}

void Reader::PrintInfo(){
    printf("UID=%04d %s\n",uid,name);
}
std::set<int> Reader::Print_record(){ 
    if(record.empty())printf("Error:No book available\n");
    return record;
}
void Reader::Borrow_book(Book b){
    record.insert(b.get_id());
}
void Reader::Return_book(Book b){
    if(record.count(b.get_id())){
        record.erase(b.get_id());
    }
    else{
        printf("Error:Not that book\n");
    }
}

char* Reader::get_name(){
    return name;
}