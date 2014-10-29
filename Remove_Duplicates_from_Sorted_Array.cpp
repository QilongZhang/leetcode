/*************************************************************************
	> File Name: Remove_Duplicates_from_Sorted_Array.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月29日 星期三 19时30分16秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
        int len = 0, pc = -1, pt = 0;
        while(pt < n){
            if(pc == -1 || A[pt] != A[pc]){
                A[len] = A[pt];
                ++len;
            }
            ++pt;
            ++pc;
        }
        return len;
    }
};

int main(){
    Solution st;
    int A[] = {0, 0, 1, 1, 1, 2, 3, 3, 3, 4, 4, 5, 6};
    cout<<st.removeDuplicates(A, 13);
    return 0;
}
