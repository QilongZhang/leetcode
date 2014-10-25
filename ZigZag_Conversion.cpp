/*************************************************************************
	> File Name: ZigZag_Conversion.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 16时52分16秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string convert(string s, int nRows){
        vector<string> vstr(nRows);
        int id=0, dir=1;
        for(int pt=0; pt<s.size(); ++pt){
            vstr[id].push_back(s[pt]);
            if(id==0 && id==nRows-1)
                continue;
            if(id==0)
                dir = 1;
            if(id==nRows-1)
                dir = -1;
            id += dir;
        }
        string retstr="";
        for(int i=0; i<nRows; ++i)
            retstr += vstr[i];
        return retstr;
    }
};

int main(){
    Solution st;
    string str = "PAYPALISHIRING";
    cout<<st.convert(str, 3)<<endl;
    return 0;
}
