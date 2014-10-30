/*************************************************************************
	> File Name: Divide_Two_Integers.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月30日 星期四 08时07分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor){
        bool mark = (dividend ^ divisor) & (1<<31);
        vector<unsigned int> table;
        unsigned dd = abs(dividend);
        unsigned dv = abs(divisor);
        unsigned int ret = 0;
        unsigned int tb = dv;
        int acc = 0;

        while(dd >= tb && tb != 0 && acc < 32){
            table.push_back(tb);
            ++acc;
            tb = dv<<acc;
        }
        for(int i = acc - 1; i >= 0; --i){
            if(dd < table[i])
                continue;
            dd -= table[i];
            ret += 1<<i;
        }
        return (mark?-1:1) * ret;
    }
};

int main(){
    Solution st;
    cout<<st.divide(-2147483648, 3)<<endl;
    return 0;
}
