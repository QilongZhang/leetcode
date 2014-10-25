/*************************************************************************
	> File Name: Reverse_Integer.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 17时23分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    int reverse(int x){
        int dir = (x<0) ? -1 : 1;
        x = abs(x);
        while(x && x%10 == 0){
            x /= 10;
        }
        int y = 0;
        while(x){
            y *= 10;
            y += x%10;
            x /= 10;
        }
        return y*dir;
    }
};

int main(){
    Solution st;
    cout<<st.reverse(123)<<endl;
    cout<<st.reverse(-123)<<endl;
    cout<<st.reverse(10000)<<endl;
    cout<<st.reverse(-1000)<<endl;
    return 0;
}
