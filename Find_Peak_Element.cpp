/*************************************************************************
	> File Name: Find_Peak_Element.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月06日 星期五 09时35分19秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

//O(n)



class Solution{
public:
    int findPeakElement(const vector<int> & num){
        return FPE(num, 0, num.size() - 1);
    }

private:
    int FPE(const vector<int> & num, int st, int ed){
        if(st == ed){
            return st;
        }
        int mid = (st+ed)/2;
        if(num[mid] < num[mid + 1]){
            return FPE(num, mid + 1, ed);
        }
        else{
            return FPE(num, st, mid);
        }
    }
};
