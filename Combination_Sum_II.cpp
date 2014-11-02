/*************************************************************************
	> File Name: Combination_Sum_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月02日 星期日 22时33分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
protected:
    typedef struct node{
        int val;
        int count;
        node(int v, int c) : val(v), count(c){}
    }Node;
    vector<vector<int> > vvi;
    vector<vector<Node> > vvN;
    vector<Node> vN;

protected:
    void CS2(vector<int> &num, int start, int target){
        if(target == 0){
            vvN.push_back(vN);
            return;
        }
        else if(start == num.size() || target < num[start])
            return;
        int next = start + 1;
        while(next != num.size() && num[next] == num[start]) ++next;
        for(int n = next - start; n >= 0; --n){
            vN.push_back(Node(num[start], n));
            CS2(num, next, target - n*num[start]);
            vN.pop_back();
        }
    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target){
        sort(num.begin(), num.end());
        CS2(num, 0, target);
        for(int i = 0; i < vvN.size(); ++i){
            vector<int> vi;
            for(int j = 0; j < vvN[i].size(); ++j){
                for(int k = 0; k < vvN[i][j].count; ++k)
                    vi.push_back(vvN[i][j].val);
            }
            vvi.push_back(vi);
        }
        return vvi;
    }
};

int main(){
    Solution st;
    vector<int> vi(7);
    vi[0] = 10, vi[1] = 1, vi[2] = 2, vi[3] = 7, vi[4] = 6, vi[5] = 1, vi[6] = 5;
    vector<vector<int> > vvi = st.combinationSum2(vi, 8);
    for(int i = 0; i < vvi.size(); ++i){
        for(int j = 0; j < vvi[i].size(); ++j)
            cout<<vvi[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
