/*************************************************************************
	> File Name: 3Sum.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月27日 星期一 22时38分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
protected:
    static bool my_cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0] && a[1] == b[1])
            return a[2] < b[2];
        else if(a[0] == b[0])
            return a[1] < b[1];
        else 
            return a[0] < b[0];
    }

public:
    vector<vector<int> > threeSum(vector<int> &num){
        sort(num.begin(), num.end());
        vector<vector<int> > vvi;
        vector<vector<int> > ret;
        for(int i = 0; i < num.size(); ++i){
            if(i > 0 && num[i] == num[i-1])     
                continue;
            for(int j = i + 1, k = num.size() - 1; j < k; ){
                if(num[j] + num[k] > -num[i]){
                    --k;
                }
                else if(num[j] + num[k] < -num[i]){
                    ++j;
                }
                else{
                    vector<int> vi;
                    vi.push_back(num[i]), vi.push_back(num[j]), vi.push_back(num[k]);
                    vvi.push_back(vi);
                    while(j < k && num[j] == num[j+1])  ++j;
                    ++j;
                    while(j < k && num[k] == num[k+1])  --k;
                    --k;
                }
            }
        }
        sort(vvi.begin(), vvi.end(), my_cmp);
        for(int l = 0, pc = -1; l < vvi.size(); ++l, ++pc){
            if(pc != -1 && vvi[l][0] == vvi[pc][0] && vvi[l][1] == vvi[pc][1] && vvi[l][2] == vvi[pc][2])
                continue;
            ret.push_back(vvi[l]);
        }
        return ret;
    }
};

int main(){
    Solution st;
    vector<int> num(6);
    num[0]= -1;
    num[1] = 0;
    num[2] = 1;
    num[3] = 2;
    num[4] = -1;
    num[5] = -4;
    vector<vector<int> > vvi = st.threeSum(num);
    for(int i = 0; i < vvi.size(); ++i)
        cout<<vvi[i][0]<<' '<<vvi[i][1]<<' '<<vvi[i][2]<<endl;
    return 0;
}
