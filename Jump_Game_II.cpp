/*************************************************************************
	> File Name: Jump_Game_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 14时21分11秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(int A[], int n){
        vector<bool> vb(n, true);
        vector<int> vi(n, 0);
        int ret = 0, st = 0, ed = 0, ted = 0, pre = 0, i, j;
        vb[0] = false;
        while(st <= ed){
            for(i = st; i <= ed; ++i){
                for(j = pre-vi[i] + 1; j <= A[vi[i]]; ++j){
                    ++pre;
                    if(vi[i] + j == n - 1)
                        return ret;
                    if(vi[i] + j < n && vb[vi[i]+j])
                        vi[++ted] = vi[i] + j, vb[vi[i]+j] = false;
                }
            }
            ++ret;
            st = ed + 1;
            ed = ted;
        }
        return 0;
    }
};

int main(){
    int A[] = {1, 2, 3, 4};
    Solution st;
    cout<<st.jump(A, 4)<<endl;
    return 0;
}
