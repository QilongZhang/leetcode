/*************************************************************************
	> File Name: String_to_Integer.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 17时43分26秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution{
public:
    int atoi(const char *str){
        string vc;
        int ret = 0;
        bool hasplus = false, hasminus = false, mark = true;
        string maxstr = "2147483647", minstr = "2147483648";
        int maxret = 2147483647, minret = -2147483648;

        for(int pt=0; str[pt]!='\0'; ++pt){
            if(str[pt] != ' ')
                mark = false;
            if(str[pt] == '+' && hasplus)
                return 0;
            if(str[pt] == '-' && hasminus)
                return 0;
            if(str[pt] == '+')
                hasplus = true;
            else if(str[pt] == '-')
                hasminus = true;
            else if(str[pt] ==' ' && mark)
                continue;
            else if(str[pt] <= '9' && str[pt] >= '0')
                vc.push_back(str[pt]);
            else 
                break;
        }

        if(hasplus && hasminus)
            return 0;
        
        for(int st = 0; st < vc.size(); ++st){
            if(vc[st] != '0'){
                vc = vc.substr(st);
                break;
            }
        }

        if(!hasminus && vc.size() == maxstr.size() && strcmp(vc.c_str(), maxstr.c_str()) >= 0){
            return maxret;
        }   

        if(!hasminus && vc.size() > maxstr.size()){
            return maxret;
        }

        if(hasminus && vc.size() == minstr.size() && strcmp(vc.c_str(), minstr.c_str()) >= 0){
            return minret;
        }

        if(hasminus && vc.size() > minstr.size()){
            return minret;
        }

        for(int ed = 0; ed < vc.size(); ++ed){
            ret *= 10;
            ret += vc[ed] - '0';
        }
        return (hasminus?-1:1) * ret;
    }
};

int main(){
    Solution st;
    cout<<st.atoi("  -00 12a42")<<endl;
    return 0;
}
