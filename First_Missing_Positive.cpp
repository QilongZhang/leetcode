/*************************************************************************
	> File Name: First_Missing_Positive.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月03日 星期一 10时18分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
protected:
    const static int MARK = 1<<30;

public:
    int firstMissingPositive(int A[], int n){
        int minv = MARK, i;
        for(int i = 0; i < n; ++i){//get the first positive integer in the array
            if(A[i] <= 0)
                A[i] = MARK;
            else
                minv = min(minv, A[i]);
        }
        //if(minv == MARK)//return the First Positive Integer 1
        if(minv != 1)//开头的必须是1,开始写的是找到第一个不构成连续的正数
            return 1;
        for(i =0; i < n; ++i){//make MARK
            if(A[i] >= minv + n)
                A[i] = MARK;
        }
        for(i = 0; i < n; ++i){
            if(A[i] == MARK || A[i] == i + minv)
                continue;
            while(A[i] != MARK && A[i] != i + minv){
                int tmp = A[A[i] - minv];
                A[A[i] - minv] = A[i];
                A[i] = (tmp==A[i])?MARK:tmp; 
            }
        }
        for(i = 0; i < n; ++i)
            if(A[i] != i + minv)
                return i + minv;
        return minv + n;
    }
};

int main(){
    Solution st;
    int A[] = {1, 1};
    cout<<st.firstMissingPositive(A, 1)<<endl;
    return 0;
}
