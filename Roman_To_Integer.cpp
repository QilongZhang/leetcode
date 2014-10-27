/*************************************************************************
	> File Name: Roman_To_Integer.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月27日 星期一 12时13分35秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
    int romanToInt(string s){
        map<char, int> umci;
        umci.insert(make_pair('I', 1));
        umci.insert(make_pair('V', 5));
        umci.insert(make_pair('X', 10));
        umci.insert(make_pair('L', 50));
        umci.insert(make_pair('C', 100));
        umci.insert(make_pair('D', 500));
        umci.insert(make_pair('M', 1000));
        int ret = 0;
        int i = 0;
        int len = s.length();
        for(i = 0; i < len - 1; ++i){
            if(umci[s[i]] < umci[s[i+1]])
                ret -= umci[s[i]];
            else
                ret += umci[s[i]];
        }
        ret += umci[s[i]];
        return ret;
    }
};

int main(){
    Solution st;
    cout<<st.romanToInt("DCXXI")<<endl;
    return 0;
}
