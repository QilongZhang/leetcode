/*************************************************************************
	> File Name: Search_in_Rotated_Sorted_Array_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 01时34分38秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
protected:
    bool S(int A[], int s, int e, int t){
        if(s > e)
            return false;
        else if(s == e)
            return A[s] == t;
        int mid = (s + e)/2;
        if(A[mid] == t)
            return true;
        else if(A[mid] == A[s])
            return S(A, s, mid - 1, t) || S(A, mid + 1, e, t);
        else if(A[mid] > A[s]){
            int st = s, ed = mid, md;
            while(st <= ed){
                md = (st + ed)/2;
                if(A[md] == t)
                    return true;
                else if(A[md] > t)
                    ed = md - 1;
                else
                    st = md + 1;
            }
            return S(A, mid + 1, e, t);
        }
        else{
            int st = mid, ed = e, md;
            while(st <= ed){
                md = (st + ed)/2;
                if(A[md] == t)
                    return true;
                else if(A[md] > t)
                    ed = md - 1;
                else
                    st = md + 1;
            }
            return S(A, s, mid - 1, t);
        }
    }

public:
    bool search(int A[], int n, int target){
        return n && S(A, 0, n - 1, target);
    }
};
