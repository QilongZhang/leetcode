/*************************************************************************
	> File Name: Letter_Combinations_of_a_Phone_Number.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 14时10分31秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
protected:
    vector<string> vstr = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> rets;
    string vs;

    void LC(string str){
        if(str.length() == 0){
            rets.push_back(vs);
            return;
        }
        for(int i = 0; i < vstr[str[0]-'0'].length(); ++i){
            vs.push_back(vstr[str[0]-'0'][i]);
            LC(str.subStr(1));
            vs.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits){
        LC(digits);
        return rets;
    }
};
