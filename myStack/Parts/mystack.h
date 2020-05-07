#ifndef __Mystack_H__
#define __Mystack_H__
class mystack
{
private:
    int Top;
    int *data;
    const int DSIZE=10;
    
public:
    mystack(){};
    mystack(int size){
        size=(size>0?size:DSIZE);
        data=new int[size];
        Top=0;
    }

    ~mystack(){
        delete []data;
    }
    void push(int x);
    void pop();
    bool empty();
    int top();
};
#endif