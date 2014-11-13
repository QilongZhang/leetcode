/*************************************************************************
	> File Name: Combinations.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 02时19分54秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
protected:
    vector<vector<int> > vvi;
    vector<int> vi;

protected:
    void C(int n, int k, int s, int c){
        if(c == k){
            vvi.push_back(vi);
            return;
        }
        for(int i = s; i <= n - k + c + 1; ++i ){
            vi.push_back(i);
            C(n, k, i + 1, c + 1);
            vi.pop_back();
        }
    }

public:
    vector<vector<int> > combine(int n, int k){
        C(n, k, 1, 0);
        return vvi;
    }
};
