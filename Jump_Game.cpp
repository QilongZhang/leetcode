/*************************************************************************
	> File Name: Jump_Game.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 23时33分48秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    bool canJump(int A[], int n){
        int pt = 0;
        for(int i = 0; i <= pt; ++i){
            pt = max(pt, A[i] + i);
            if(pt >= n - 1)
                return true;
        }
        return false;
    }
};
