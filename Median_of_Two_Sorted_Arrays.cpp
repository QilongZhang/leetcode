/*************************************************************************
	> File Name: Median_of_Two_Sorted_Arrays.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月24日 星期五 21时07分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
protected:
    double findKthNum(int A[], int m, int B[], int n, int k){
        if(m<n)
            return findKthNum(B, n, A, m, k);
        if(n==0)
            return A[k-1];
        if(k==1)
            return min(A[0], B[0]);
        int pt = min(n-1, k/2-1);
        if(A[k/2-1] >= B[pt])
            return findKthNum(A, m, B+pt+1, n-pt-1, k-pt-1);
        else
            return findKthNum(A+k/2, m-k/2, B, n, k-k/2);
    }

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n){
        if((m+n)%2 == 0){
            return (findKthNum(A, m, B, n,(m+n)/2) + findKthNum(A, m, B, n, (m+n)/2+1))/2;
        }
        else{
            return findKthNum(A, m, B, n, (m+n)/2 + 1);
        }
    }
};

int main(){
    int A[]={2, 3, 4, 5, 6};
    int B[]={-1, 4, 4, 5};
    Solution st;
    cout<<st.findMedianSortedArrays(A, 5, B, 4)<<endl;
    return 0;
}
