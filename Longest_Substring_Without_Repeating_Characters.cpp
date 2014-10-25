/*************************************************************************
	> File Name: Longest_Substring_Without_Repeating_Characters.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 11时11分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int table[260];
        for(int id = 0; id < 260; ++id)
            table[id] = -1;
        int len = 0, curlen = 0;
        for(int pt = 0; pt < s.length(); ++pt){
            len = max(len, curlen);
            if(table[s[pt]] < pt-curlen){
                ++curlen;
                table[s[pt]] = pt;
            }
            else{
                curlen = pt - table[s[pt]];
                table[s[pt]] = pt;
            }
        }
        len = max(len, curlen);
        return len;
    }
};

int main(){
    Solution st;
    string str = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout<<st.lengthOfLongestSubstring(str)<<endl;
    return 0;
}
