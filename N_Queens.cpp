/*************************************************************************
	> File Name: N_Queens.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 23时24分31秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
protected:
    vector<int> vi;
    vector<vector<string> > vvs;

    void trans(int n){
        vector<string> vs(n, string(n, '.'));
        for(int i = 0; i < n; ++i)
            vs[i][vi[i]] = 'Q';
        vvs.push_back(vs);
    }

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
            trans(n);
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
    vector<vector<string> > solveNQueens(int n){
        TN(n, 0);
        return vvs;    
    }
};
