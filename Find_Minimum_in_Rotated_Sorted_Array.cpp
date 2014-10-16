/*************************************************************************
	> File Name: Find_Minimum_in_Rotated_Sorted_Array.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月16日 星期四 22时12分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
protected:
    int find(vector<int> &num, int st, int end){
        if(st==end){
            return num[st];
        }
        else if(st == end - 1){
            return min(num[st], num[end]);
        }
        if(num[(st+end)/2] > num[st]){
            return min(num[st], find(num, (st+end)/2, end));
        }
        else{
            return find(num, st, (st+end)/2);
        }
    }
    
public:
    int findMin(vector<int> &num) {
        return find(num, 0, num.size() - 1);
    }
};

int main(){
    /*...*/
    return 0;
}
