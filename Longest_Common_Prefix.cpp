/*************************************************************************
	> File Name: Longest_Common_Prefix.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月27日 星期一 20时22分10秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
protected:
    string LCP(vector<string> &strs, int st, int ed){
        if(st == ed)
            return strs[st];
        string s1 = LCP(strs, st, (st+ed)/2);
        string s2 = LCP(strs, (st+ed)/2 + 1, ed);
        string retstr;
        int p1 = 0, p2 = 0;
        while(p1 != s1.length() && p2 != s2.length() && s1[p1] == s2[p2]){
            retstr.push_back(s1[p1]);
            ++p1;
            ++p2;
        }
        return retstr;
    }
    
public:
    string longestCommonPrefix(vector<string> &strs){
        if(strs.size() == 0)
            return "";
        return LCP(strs, 0, strs.size() - 1);
    }
};

