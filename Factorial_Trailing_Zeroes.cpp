/*************************************************************************
	> File Name: Factorial_Trailing_Zeroes.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月04日 星期三 10时05分23秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int trailingZeroes(int n){
        int ret = 0;
        while(n){
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
};

