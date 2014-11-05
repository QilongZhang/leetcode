/*************************************************************************
	> File Name: Valid_Number.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 20时10分32秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool isNumber(const char *s){
        const char *pst = s, *ped = s, *pos = s;
        while(*pst != '\0' && *pst == ' ') ++pst;
        while(*pos != '\0'){
            if(*pos != ' ')
                ped = pos;
            ++pos;
        }
        bool hasp = false;
        bool hase = false;
        bool hasnbe = false;
        bool hasnae = false;
        for(pos = pst; pos <= ped; ++pos){
            if(*pos == '.' && !hasp && !hase){
                hasp = true;
            }
            else if(*pos == 'e' && !hase && hasnbe){
                hase = true;
            }
            else if(*pos >= '0' && *pos <= '9'){
                if(hase)
                    hasnae = true;
                else
                    hasnbe = true;
            }
            else if((*pos == '-' || *pos == '+') && (pos == pst || *(pos-1) == 'e'))
                continue;
            else
                return false;
        }
        if(hase)
            return hasnae;
        else
            return hasnbe;
    }
};

int main(){
    Solution st;
    string str;
    while(cin>>str){
        if(st.isNumber(str.c_str()))
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }
}

