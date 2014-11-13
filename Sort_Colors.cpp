/*************************************************************************
	> File Name: Sort_Colors.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月13日 星期四 19时27分57秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    void sortColors(int A[], int n){
        int pred = 0, pblue = n -1, pt;
        for(pt = 0; pt < n; ++pt){
            if(A[pt] == 1)
                continue;
            else if(A[pt] == 0){
                if(pt == pred)
                    ++pred;
                else{
                    A[pt] = A[pred];
                    A[pred++] = 0;
                    --pt;
                }
            }
            else if(A[pt] == 2){
                if(pt >= pblue)
                    break;
                else{
                    A[pt] = A[pblue];
                    A[pblue--] = 2;
                    --pt;
                }
            }
        }
    }
};

int main(){
    Solution st;
    int A[] = {2, 1, 2};
    st.sortColors(A, 3);
    return 0;
}
