/*************************************************************************
	> File Name: Implement_strStr.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月29日 星期三 19时41分42秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    char *strStr(char *haystack, char *needle){
        string Pstr(haystack), Sstr(needle);
        size_t pos = Pstr.find(Sstr);
        if(pos == string::npos)
            return NULL;
        else
            return haystack+pos;
    }
};
