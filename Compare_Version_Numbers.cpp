/*************************************************************************
	> File Name: Compare_Version_Numbers.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月03日 星期二 16时19分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Solution{
public:
    int compareVersion(string version1, string version2){
        while(!version1.empty() || !version2.empty()){
            size_t pos1 = version1.find('.');
            size_t pos2 = version2.find('.');
            int value1 = 0, value2 = 0;
            if(pos1 == string::npos && !version1.empty()){
                sscanf(version1.c_str(), "%d", &value1);
                version1.clear();
            }
            else{
                string sunStr = version1.substr(0, pos1);
                version1 = version1.substr(pos1 + 1);
                sscanf(sunStr.c_str(), "%d", &value1);
            }
            if(pos2 == string::npos && !version2.empty()){
                sscanf(version2.c_str(), "%d", &value2);
                version2.clear();
            }
            else{
                string sunStr = version2.substr(0, pos2);
                version2 = version2.substr(pos2 + 1);
                sscanf(sunStr.c_str(), "%d", &value2);
            }           
            if(value1 > value2){
                return 1;
            }
            else if(value1 < value2){
                return -1;
            }
        }
        return 0;
    }
};

