/*************************************************************************
	> File Name: Palindrome_Number.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 19时14分48秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
protected:
    int reverse(int x){
        int dir = (x<0) ? -1 : 1;
        x = abs(x);
        while(x && x%10 == 0){
            x /= 10;
        }
        int y = 0;
        while(x){
            y *= 10;
            y += x%10;
            x /= 10;
        }
        return y;
    }
public:
    bool isPalindrome(int x){
        int y = reverse(x);
        return (x==y)?true:false;
    }    
};
