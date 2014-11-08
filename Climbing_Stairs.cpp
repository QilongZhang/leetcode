/*************************************************************************
	> File Name: Climbing_Stairs.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 19时11分52秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
