#include<cstdio>
#include"Parts/mystack.h"

int main(){
    mystack s(150);
    for(int i=1;i<=15;++i){
        s.push(i);
    }
    while(!s.empty()){
        printf("%d\n",s.top());s.pop();
    }
    return 0;
}
