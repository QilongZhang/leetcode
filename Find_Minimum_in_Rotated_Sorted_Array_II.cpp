/*************************************************************************
	> File Name: Find_Minimum_in_Rotated_Sorted_Array_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月26日 星期日 17时12分28秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
protected:
    int find(vector<int> &num, int st, int ed){
        if(st == ed || num[ed] > num[st])
            return num[st];
        if(num[ed] == num[st])
            return find(num, st, ed-1);
        else if(st+1 == ed)
            return num[ed];
        else if(num[(st+ed)/2] >= num[st])
            return find(num, (st+ed)/2 + 1, ed);
        else
            return find(num, st, (st+ed)/2);
    }

public:
    int findMin(vector<int> &num){
        return find(num, 0, num.size()-1);
    }
};

