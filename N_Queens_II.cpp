/*************************************************************************
	> File Name: N_Queens_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 18时52分44秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
protected:
    vector<int> vi;
    int ret;

    bool check(int col){
        int cr = vi.size(), cc = col;
        int pr, pc;
        for(int i = 0; i < vi.size(); ++i){
            if(vi[i] == cc)
                return false;
            pr = i, pc = vi[i];
            if(abs(pr-cr) == abs(pc-cc))
                return false;
        }
        return true;
    }

    void TN(int n, int k){
        if(k == n){
            ++ret;
            return;
        }
        for(int i = 0; i < n; ++i){
            if(check(i)){
                vi.push_back(i);
                TN(n, k+1);
                vi.pop_back();
            }
        }
    }

public:
    int totalNQueens(int n){
        ret = 0;
        TN(n, 0);
        return ret;    
    }
};

int main(){
    Solution st;
    cout<<st.totalNQueens(12)<<endl;
    return 0;
}
