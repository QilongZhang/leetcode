/*************************************************************************
	> File Name: Regular_Expression_Matching.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月29日 星期三 20时16分53秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    bool isMatch(const char *s, const char *p){
        if(*s == '\0' && *p == '\0')
            return true;
        else if(*s == '\0' && *(p+1) != '*')
            return false;
        else if(*s == '\0' && *(p+1) == '*')
            return isMatch(s, p+2);
        else if(*p == '\0')
            return false;
        else if(*(p+1) != '*'){
            if(*s == *p || *p == '.')
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else if(*(p+1) == '*'){
            if(*s == *p || *p == '.')
                return isMatch(s+1, p) || isMatch(s, p+2);
            else
                return isMatch(s, p+2);
        }
    }
};

int main(){
    Solution st;
    if(st.isMatch("aab", "c*a*b"))
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
    return 0;
}
