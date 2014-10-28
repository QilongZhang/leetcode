/*************************************************************************
	> File Name: Valid_Parentheses.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 22时12分04秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> sc;
        for(int i = 0; i < s.length(); ++i){
            if(sc.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
                sc.push(s[i]);
            else{
                if(sc.empty())
                    return false;
                char ch = sc.top();
                if(s[i] == ')' && ch != '(')
                    return false;
                if(s[i] == ']' && ch != '[')
                    return false;
                if(s[i] == '}' && ch != '{')
                    return false;
                sc.pop();
            }
        }
        return sc.empty();
    }
};

