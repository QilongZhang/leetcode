/*************************************************************************
	> File Name: Length_of_Last_Word.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 23时42分31秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(const char *s){
        int ret = 0;
        int len = 0;
        bool mark = false;
        while(*s != '\0'){
            if(*s == ' ' && mark){
                ret = len;
                len = 0;
                mark = false;
            }
            else if(*s != ' '){
                mark = true;
                ++len;
            }
            ++s;
        }
        if(mark){
            ret = len;
        }
        return ret;
    }
};

int main(){
    Solution st;
    cout<<st.lengthOfLastWord("Hello world")<<endl;
    return 0;
}
