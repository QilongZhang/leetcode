/*************************************************************************
	> File Name: Count_and_Say.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月02日 星期日 13时55分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution{
public:
    string countAndSay(int n){
        string s1("1"), s2;
        for(int i = 1; i < n; ++i){
            int len = 0, pt, pre;
            char str[10];
            for(pt = 0, pre = -1; pt != s1.length(); ++pt, ++pre){
                if(pre == -1 || s1[pt] == s1[pre])
                    ++len;
                else{
                    sprintf(str, "%d", len);
                    s2 += str;
                    s2.push_back(s1[pre]);
                    len = 1;
                }
            }
            sprintf(str, "%d", len);
            s2 += str;
            s2.push_back(s1[pre]);
            s1 = s2;
            s2.clear();
        }
        return s1;
    }
};

int main(){
    Solution st;
    cout<<st.countAndSay(9)<<endl;
    return 0;
}
