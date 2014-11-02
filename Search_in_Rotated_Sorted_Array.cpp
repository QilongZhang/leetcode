/*************************************************************************
	> File Name: Search_in_Rotated_Sorted_Array.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月02日 星期日 11时47分04秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
protected:
    int ST(int A[], int st, int ed, int target){
        int mid = (st + ed)/2;
        if(A[ed] >= A[st]){//直接二分查找
            while(st <= ed){
                mid = (st + ed)/2;
                if(A[mid] == target)
                    return mid;
                else if(A[mid] > target)
                    ed = mid - 1;
                else
                    st = mid + 1;
            }
            return -1;
        }
        else{
            return max(ST(A, st, mid, target), ST(A, mid + 1, ed, target));
        }
    }

public:
    int search(int A[], int n, int target){
        return ST(A, 0, n - 1, target);
    }
};

