/*************************************************************************
	> File Name: 3SumClosest.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 08时45分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int> &num, int target){
        int ret = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i){
            int c = target - num[i];
            int a = i + 1, b = num.size() - 1;
            while(a < b){
                if(num[a] + num[b] == c)
                    return target;
                ret = abs(num[a] + num[b] - c) > abs(ret - target) ? ret : (num[a] + num[b] + num[i]);
                if(num[a] + num[b] < c){
                    ++a;  
                }
                else{
                    --b;
                }
            }
        }
        return ret;
    }    
};

int main(){
    Solution st;
    vector<int> vi(4);
    vi[0] = 0, vi[1] = 1, vi[2] = 1, vi[3] = 1;
    st.threeSumClosest(vi, -100);
    return 0;
}
