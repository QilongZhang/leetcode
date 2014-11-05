/*************************************************************************
	> File Name: Minimum_Window_Substring.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 21时54分10秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

class Solution{
protected:
    typedef struct node{
        char ch;
        int pos;
        node(char c, int p) : ch(c), pos(p){}
    }Node;

public:
    string minWindow(string s, string T){
        map<char, int> Tmci;
        map<char, int> Smci;
        queue<Node> qN;
        for(int i = 0; i < T.length(); ++i)
            ++Tmci[T[i]];
        int st = 0, ed = s.length() + 1, len = 0;
        for(int pos = 0; pos < s.length(); ++pos){
            if(Tmci.find(s[pos]) == Tmci.end())
                continue;
            ++Smci[s[pos]];
            qN.push(Node(s[pos], pos));
            if(Smci[s[pos]] <= Tmci[s[pos]])
                ++len;
            if(len == T.length()){
                if(pos - qN.front().pos < ed - st)
                    st = qN.front().pos, ed = pos;
                --Smci[qN.front().ch];
                qN.pop();
                --len;
            }
            while(!qN.empty()){
                if(Smci[qN.front().ch] > Tmci[qN.front().ch]){
                    --Smci[qN.front().ch];
                    qN.pop();
                }
                else
                    break;
            }
        }
        if(ed == s.length() + 1)
            return "";
        else
            return s.substr(st, ed - st + 1);
    }
};

int main(){
    string S = "ADOBECODEBANC";
    string T = "ABCF";
    Solution st;
    cout<<st.minWindow(S, T)<<endl;
    return 0;
}
