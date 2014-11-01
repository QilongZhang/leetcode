/*************************************************************************
	> File Name: Longest_Valid_Parentheses.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月01日 星期六 23时03分44秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    int longestValidParentheses(string s){
        int ret = 0, len = 0, cl = 0, pt = 0, pre = 0;
        while(pt != s.size()){
            if(s[pt] == ')' && cl == 0){
                ret = max(ret, len);
                pre = pt + 1;
                cl = 0;
                len = 0;
            }
            else if(s[pt] == ')'){
                ++len;
                --cl;
            }
            else if(s[pt] == '(')
                ++cl;
            ++pt;
        }
        len = 0, cl = 0;
        for(pt = pt -1; pt >= pre; --pt){
            if(s[pt] == '(' && cl == 0){
                ret = max(ret, len);
                len = 0;
            }
            else if(s[pt] == '('){
                ++len;
                --cl;
            }
            else
                ++cl;
        }
        return 2*max(len, ret);
    }
};

