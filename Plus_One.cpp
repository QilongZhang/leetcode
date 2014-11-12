/*************************************************************************
	> File Name: Plus_One.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月12日 星期三 17时36分53秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int> &digits){
        int ans = 0;
        digits[digits.size() - 1] += 1;
        for(int p = (int)digits.size() - 1; p >= 0; --p){
            if(p == 0)
                ans = digits[p]/10;
            else
                digits[p - 1] += digits[p]/10;
            digits[p] %= 10;
        }
        if(ans){
            digits.push_back(digits[digits.size() - 1]);
            for(int i = digits.size() - 2; i > 0; --i)
                digits[i] = digits[i-1];
            digits[0] = ans;
        }
        return digits;
    }
};

