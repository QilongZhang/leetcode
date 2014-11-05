/*************************************************************************
	> File Name: Permutations.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 15时08分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int> > permuteUnique(vector<int> &num){
        sort(num.begin(), num.end());
        vector<vector<int> > vvi;
        vvi.push_back(num);
        int ed = 0;
        for(int i = 1; i < num.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(num[i] == num[j])
                    continue;
                if(j != i - 1 && num[j] == num[j + 1])
                    continue;
                int pre = vvi.size() - 1, n; 
                for(int k = 0; k <= ed; ++k){
                    vector<int> vi = vvi[k];
                    vi[i] = num[j];
                    for(int m = 0; m < i; ++m)
                        if(vi[m] == num[j]){
                            vi[m] = num[i];
                            for(n = pre; n < vvi.size(); ++n)
                                if(vi == vvi[n])
                                    break;
                            if(n == vvi.size())
                                vvi.push_back(vi);
                            vi[m] = num[j];
                        }
                }
            }
            ed = vvi.size() - 1;
        }
        return vvi;
    }
};

int main(){
    vector<int> vi(4);
    vi[0] = 2, vi[1] = 1, vi[2] = 1, vi[3] = 2;
    Solution st;
    vector<vector<int> > vvi = st.permute(vi);
    for(int i = 0; i < vvi.size(); ++i){
        for(int j = 0; j < vvi[i].size(); ++j)
            cout<<vvi[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
