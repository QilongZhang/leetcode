/*************************************************************************
	> File Name: Maximum_Product_Subarray.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月16日 星期四 22时37分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
protected:
    int subPro(int A[], int n){
        if(n<=1)
            return A[0];
        int a = 1, b = 1, c = 1;
        int i, j, k;
        for(i=0; i<n; ++i)
            a *= A[i];
        if(a > 0)
            return a;
        for(j=0; A[j] > 0; ++j)
            b *= A[j];
        b *= A[j];
        for(k=n-1; A[k] > 0; --k)
            c *= A[k];
        c *= A[k];
        return max(a/b, a/c);
    }

public:
    int maxProduct(int A[], int n){
        int ret = 1<<31;
        int *ptr = A;
        int pt = 0;
        while(ptr + pt != A + n){
            if(ptr[pt] == 0){
                ret = max(max(ret, 0), subPro(ptr, pt));
                ptr = ptr + pt + 1;
                pt = 0;
            }
            else
                ++pt;
        }
        if(pt != 0)
            ret = max(ret, subPro(ptr, pt));
        return ret;
    }   
};

int main(){
    int A[] = {-1, -2, -3, 0};
    Solution st;
    cout<<st.maxProduct(A, 4)<<endl;
    return 0;
}
