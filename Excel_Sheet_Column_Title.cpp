/*************************************************************************
	> File Name: Excel_Sheet_Column_Title.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月03日 星期二 15时35分05秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    string convertToTitle(int n){
        string strRet;
        while(n){
            int mod = n % 26;
            if(mod == 0){
                strRet.insert(strRet.begin(), 'Z');
                n -= 26;
            }
            else{
                strRet.insert(strRet.begin(), 'A' + mod - 1);
                n -= mod;
            }
            n /= 26;
        }
        return strRet;
    }
};

