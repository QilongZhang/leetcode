/*************************************************************************
	> File Name: Scramble_String.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 14时43分12秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution{
protected:
    bool check(string s1, string s2){
        map<char, int> m1, m2;
        for(int i = 0; i < s1.length(); ++i)
            ++m1[s1[i]], ++m2[s2[i]];
        for(map<char, int>::iterator it = m1.begin(); it != m1.end(); ++it){
            if(m2.find(it->first) == m1.end() || m2[it->first] != it->second)
                return false;
        }
        return true;
    }

public:
    bool isScramble(string s1, string s2){
        if(s1.empty() || s1 == s2)
            return true;
        bool m1 = false, m2 = false;
        for(int i = 1; i < s1.length() && !m1 && !m2; ++i){
            if(check(s1.substr(0, i), s2.substr(0, i))){
                m1 = isScramble(s1.substr(0, i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i));
            }
            if(check(s1.substr(0, i), s2.substr(s2.length()-i))){
                m2 = isScramble(s1.substr(0, i), s2.substr(s2.length()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.length()-i));
            }
        }
        return m1 || m2;
    }
};

int main(){
    Solution st;
    string s1 = "hobobyrqd", s2 = "hbyorqdbo";
    if(st.isScramble(s1, s2))
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
}
