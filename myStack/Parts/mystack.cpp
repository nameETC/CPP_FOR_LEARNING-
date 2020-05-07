#include"mystack.h"




void mystack::push(int x){
    data[++Top]=x;
}
void mystack::pop(){
    Top--;
}
bool mystack::empty(){
    return Top==0;
}
int mystack::top(){
    return data[Top];
}