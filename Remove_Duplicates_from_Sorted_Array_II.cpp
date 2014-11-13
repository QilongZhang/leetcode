/*************************************************************************
	> File Name: Remove_Duplicates_from_Sorted_Array_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 03时19分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
        int pt = 0, cot = 1;
        for(int i = 1; i < n; ++i){
            if(A[i] != A[pt]){
                cot = 1;
                A[++pt] = A[i];
            }
            else if(cot == 1){
                cot = 2;
                A[++pt] = A[i];
            }
            else
                continue;
        }
        return min(n, pt + 1);
    }
};
