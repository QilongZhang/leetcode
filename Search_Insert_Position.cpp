/*************************************************************************
	> File Name: Search_Insert_Position.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月02日 星期日 12时44分55秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int searchInsert(int A[], int n, int target){
        int s = 0, e = n - 1, mid;
        while(s <= e){
            mid = (s + e)/2;
            if(A[s] > target)
                return s;
            else if(A[e] < target)
                return e + 1;
            if(A[mid] == target)
                return mid;
            else if(A[mid] >= target)
                e = mid;
            else
                s = mid + 1;
        }
    }
};
