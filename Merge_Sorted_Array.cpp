/*************************************************************************
	> File Name: Merge_Sorted_Array.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月13日 星期四 20时46分36秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    void merge(int A[], int m, int B[], int n){
        int pt = m + n - 1, pA = m -1, pB = n -1;
        while(pA != -1 && pB != -1){
            if(A[pA] >= B[pB]){
                A[pt] = A[pA];
                --pA;
                --pt;
            }
            else{
                A[pt] = B[pB];
                --pB;
                --pt;
            }
        }
        if(pA == -1 && pB == -1)
            return;
        else if(pA == -1)
            while(pB != -1) A[pt--] = B[pB--];
        else
            while(pA != -1) A[pt--] = A[pA--];
    }
};
