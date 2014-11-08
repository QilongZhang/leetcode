/*************************************************************************
	> File Name: Sqrt_x.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 11时35分50秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int sqrt(int x){
        unsigned x1 = 0, x2 = 1<<17 - 1, x3, y;
        while(x1 <= x2){
            x3 = (x1 + x2)/2;
            y = x3 * x3;
            if(y == x)
                return x3;
            else if(y > x)
                x2 = x3;
            else
                x1 = x3;
            if(x1 == x2 || x1 + 1 == x2)
                return x1;
        }
    }
};

int main(){
    Solution st;
    cout<<st.sqrt(2147483647)<<endl;
    return 0;
}
