/*************************************************************************
	> File Name: Unique_Binary_Search_Trees.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 18时15分34秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numTrees(int n){
        if(n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i= 2; i <= n; ++i){
            for(int k = 1; k <= i; ++k)
                dp[i] += dp[k-1]*dp[i-k];
        }
        return dp[n];
    }
};

int main(){
    Solution st;
    cout<<st.numTrees(3)<<endl;
    return 0;
}
