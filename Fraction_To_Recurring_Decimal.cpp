/*************************************************************************
	> File Name: Fraction_To_Recurring_Decimal.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月04日 星期三 15时21分13秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

class Solution{
public:
    string fractionToDecimal(int nume, int denm){
        int flag = (nume < 0 ? -1 : 1) * (denm < 0 ? -1 : 1);
        flag = nume == 0 ? 1 : flag;
        long long numerator = (long long)nume * (nume < 0 ? -1 : 1);
        long long denminator = (long long)denm * (denm < 0 ? -1 : 1);

        long long IntegerPart = numerator / denminator;
        numerator = numerator % denminator;
        
        set<long long> si;
        map<long long, int> mii;
        string DecimalPart;
        int count = 0;
        while(numerator){
            if(si.find(numerator) != si.end()){
                break;
            }
            si.insert(numerator);
            mii.insert(std::pair<long long, int>(numerator, count));
            numerator *= 10;
            DecimalPart.push_back('0' + numerator / denminator);
            numerator %= denminator; 
            ++count;
        }

        string strRet;
        if(flag == -1){
            strRet.push_back('-');
        }
        char c2sBuf[50];
        sprintf(c2sBuf, "%lld", IntegerPart);
        strRet += c2sBuf;
        if(!DecimalPart.empty()){
            if(numerator == 0){
                strRet += "." + DecimalPart;
            }
            else{
                int pos = mii.find(numerator)->second;
                strRet += "." + DecimalPart.substr(0, pos);
                strRet += "(" + DecimalPart.substr(pos) + ")";
            }
        }

        return strRet; 
    }
};


