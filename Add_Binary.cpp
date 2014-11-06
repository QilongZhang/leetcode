/*************************************************************************
	> File Name: Add_Binary.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月06日 星期四 17时45分07秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        vector<int> vi;
        int pa, pb;
        for(pa = a.size() - 1, pb = b.size() - 1; pa >= 0 && pb >= 0; --pa, --pb){
            vi.push_back(a[pa] - '0' + b[pb] - '0');
        }
        if(pa < 0)
            a = b, pa = pb;
        for(; pa >= 0; --pa)
            vi.push_back(a[pa] - '0');
        for(int i = 0; i < vi.size(); ++i){
            int j = vi[i]/2;
            vi[i] = vi[i]%2;
            if(i == vi.size() - 1 && j != 0)
                vi.push_back(j);
            else if(j != 0)
                vi[i+1] += j;
        }
        string str;
        for(int k = vi.size() - 1; k >= 0; --k)
            str += char(vi[k]+'0');
        return str;
    }
};

int main(){
    Solution st;
    cout<<st.addBinary("1", "111");
    return 0;
}
