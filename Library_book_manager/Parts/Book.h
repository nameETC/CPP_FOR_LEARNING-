#ifndef __Book_H__
#define __Book_H__

#include<cstring>
#include<string>

class Book
{   
    private:
        int reader_id;//借阅人uid
        int id;
        char name[101];
        int state;
        
    public:
        Book(){};
        Book(std::string n){
            memcpy(this->name,n.c_str(),sizeof(this->name));
        }
        ~Book(){};
        int get_state();
        void set_state(int st){state=st;}
        int get_id(){return id;};
        void set_id(int d){id=d;};
        void set_reader(int d){reader_id=d;};
        int get_reader(){return reader_id;};
        char *get_name(){return name;}
};


 
#endif