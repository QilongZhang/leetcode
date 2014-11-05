/*************************************************************************
	> File Name: Decode_Ways.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 21时04分21秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
protected:
    int ND(const char *str, vector<int> &vi, int n){
        if(*str == '0'){
            vi[n] = 0;
            return vi[n];
        }
        if(*str == '\0' || *(str+1) == '\0')
            return 1;
        if(vi[n] != 0)
            return vi[n];
        int x = ND(str + 1, vi, n + 1);
        int y = 0;
        if((*(str)-'0')*10 + *(str+1) - '0' <= 26)
            y = ND(str + 2, vi, n + 2);
        vi[n] = x + y;
        return vi[n];
    }

public:
    int numDecodings(string s){
        if(s.empty())
            return 0;
        vector<int> vi(s.length(), 0);
        return ND(s.c_str(), vi, 0);
    }
};

int main(){
    Solution st;
    string s = "27";
    cout<<st.numDecodings(s)<<endl;
    return 0;
}
