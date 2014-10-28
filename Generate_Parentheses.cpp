/*************************************************************************
	> File Name: Generate_Parentheses.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 22时28分29秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
protected:
    vector<string> vstr;
    string str;
    void GP(int l, int r){
        if(l == 0 && r == 0){
            vstr.push_back(str);
        }
        else if(l == 0){
            str.push_back(')');
            GP(l, r-1);
            str.pop_back();
        }
        else if(l == r){
            str.push_back('(');
            GP(l-1, r);
            str.pop_back();
        }
        else{
            str.push_back('(');
            GP(l-1, r);
            str.pop_back();
            str.push_back(')');
            GP(l, r-1);
            str.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n){
        GP(n, n);
        return vstr;
    }
};

