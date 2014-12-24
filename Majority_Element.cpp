/*************************************************************************
	> File Name: Majority_Element.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年12月24日 星期三 16时50分22秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &num){
        if(num.size() == 1)
            return num[0];
        int a = num[0], pt = 1, ct = 0;
        while(pt < num.size()){
            if(num[pt] == a)
                ++ct;
            else if(ct != 0)
                --ct;
            else 
                a = num[++pt];
            ++pt;
        }
        return a;
    }
};
