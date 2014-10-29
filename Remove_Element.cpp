/*************************************************************************
	> File Name: Remove_Element.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月29日 星期三 19时37分57秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    int removeElement(int A[], int n, int elem){
        int len = 0;
        for(int i = 0; i < n; ++i){
            if(A[i] != elem)
                A[len++] = A[i];
        }
        return len;
    }
};
