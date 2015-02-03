/*************************************************************************
	> File Name: Excel_Sheet_Column_Number.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月03日 星期二 16时07分27秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int titleToNumber(string s){
        int weight = 1;
        int valueRet = 0;
        for(int pt = s.length() - 1; pt >= 0; --pt){
            valueRet += (s[pt] - 'A' + 1) * weight;
            weight *= 26;
        }
        return valueRet;
    }
};

