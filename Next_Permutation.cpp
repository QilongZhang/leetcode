/*************************************************************************
	> File Name: Next_Permutation.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月01日 星期六 22时00分29秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int> &num){
        if(num.size() == 0 || num.size() == 1)
            return;
        int pre = num.size() - 2, pt = num.size() - 1;
        while(pre >= 0){
            if(num[pre] < num[pt])
                break;
            --pre;
            --pt;
        }
        if(pre != -1){
            int st = pt, ed = num.size() - 1, mid = (st + ed)/2 + 1;
            while(num[ed] <= num[pre]){
                if(num[mid] > num[pre]){
                    st = mid;
                    mid = (st + ed)/2 + 1;    
                }
                else{
                    ed = mid - 1;
                    mid = (st + ed)/2 + 1;    
                }    
            }
            int tmp = num[pre];
            num[pre] = num[ed];
            num[ed] = tmp;
        }
        sort(num.begin() + pt, num.end());
    }
};

int main(){
    vector<int> vi(3);
    vi[0] = 1, vi[1] = 2, vi[2] = 1;
    Solution st;
    for(int i = 0; i < vi.size(); ++i)
        cout<<vi[i]<<' ';
    st.nextPermutation(vi);
    cout<<endl;
    for(int j = 0; j < vi.size(); ++j)
        cout<<vi[j]<<' ';
    return 0;
}
