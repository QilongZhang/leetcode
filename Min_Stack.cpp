/*************************************************************************
	> File Name: Min_Stack.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月15日 星期六 23时11分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class MinStack{
protected:
    struct Stack{
        int si[100000];
        int pt;
        Stack() : pt(0) {}
    };
    Stack si;
    int MinVal;

public:
    void push(int x){
        si.si[si.pt] = x;
        if(si.pt == 0)
            MinVal = x;
        else
            MinVal = min(MinVal, x);
        ++si.pt;
    }

    void pop(){
        if(si.pt == 0)
            return;
        if(si.si[si.pt - 1] == MinVal){
            MinVal = 2147483647;
            for(int i = 0; i < si.pt - 1; ++i)
                MinVal = min(MinVal, si.si[i]);
        }
        --si.pt;
    }

    int top(){
        if(si.pt == 0)
            return 0;
        return si.si[si.pt - 1];
    }

    int getMin(){
        if(si.pt == 0)
            return 0;
        return MinVal;
    }
};

int main(){
    MinStack ms;
    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);
    cout<<ms.top()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    ms.pop();
    ms.push(2147483647);
    cout<<ms.top()<<endl<<ms.getMin()<<endl;
    ms.push(-2147483648);
    cout<<ms.top()<<endl<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    return 0;
}
