/*************************************************************************
	> File Name: Maximum_Subarray.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 18时44分38秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int maxSubArray(int A[], int n){
        if(n == 0)
            return 0;
        int ret = A[0], pt = 1, ans = A[0];
        while(pt < n){
            if(ans < 0)
                ans = A[pt];
            else
                ans = A[pt] + ans;
            ret = max(ret, ans);
            ++pt;
        }
        return ret;
    }
};
