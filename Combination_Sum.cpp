/*************************************************************************
	> File Name: Combination_Sum.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月02日 星期日 14时21分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
protected:
    vector<vector<int> > vvi;
    vector<vector<int> > ret;
    vector<int> vi;

protected:
    void CS(vector<int> &candidates, int target){
        int pid = vi.size();
        if(target == 0){
            vvi.push_back(vi);
            return;
        }
        else if(pid == candidates.size() || target < candidates[pid])
            return;
        for(int n = target/candidates[pid]; n>= 0; --n){
            vi.push_back(n);
            CS(candidates, target - n*candidates[pid]);
            vi.pop_back();
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target){
        sort(candidates.begin(), candidates.end());//递增排序
        CS(candidates, target);
        for(int i = 0; i < vvi.size(); ++i){
            vi.clear();
            for(int j = 0; j < vvi[i].size(); ++j){
                for(int k = 0; k < vvi[i][j]; ++k)
                    vi.push_back(candidates[j]);
            }
            ret.push_back(vi);
        }
        return ret;
    }
};

int main(){
    Solution st;
    vector<int> C(4);
    C[0] = 2, C[1] = 3, C[2] = 6, C[3] = 7;
    vector<vector<int> > vvi = st.combinationSum(C, 7);
    for(int i = 0; i < vvi.size(); ++i){
        for(int j = 0; j < vvi[i].size(); ++j)
            cout<<vvi[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
