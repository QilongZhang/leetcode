/*************************************************************************
	> File Name: Pow_x_n.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月18日 星期六 07时12分09秒
 ************************************************************************/

#include <iostream>
#include <algoithm>

using namespace std;

class Solution {
public:
    double pow(double x, int n){
        double ret;
        if(abs(n) == 0){
            return 1;
        }
        else if(abs(n)%2 == 0){
            ret = pow(x*x, abs(n)/2);
        }
        else{
            ret = x * pow(x, abs(n) - 1);
        }
        if(n<0) return 1/ret;
        else return ret;
    }
};
