/*************************************************************************
	> File Name: Largest_Number.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月08日 星期日 13时02分14秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution{
public:
    string largestNumber(vector<int> &num){
        vector<string> vs;
        char buf[20];
        for(int i = 0; i < num.size(); ++i){
            sprintf(buf, "%d", num[i]);
            vs.push_back(buf);
        }
        
        sort(vs.begin(), vs.end(), mycmp);

        string retStr;
        for(int i = 0; i < vs.size(); ++i){
            retStr += vs[i];
        }
        
        if(retStr[0] == '0'){
            return "0";
        }
        else{
            return retStr;
        }
    }

private:
    static bool mycmp(const string & sa, const string & sb){
        if(sa.length() == sb.length()){
            return sb < sa;
        }
        else if(sa.length() > sb.length()){
            if(sa.find(sb) == 0){
                return mycmp(sa.substr(sa.find(sb) + sb.length()), sb);
            }
            else{
                return sb < sa;
            }
        }
        else{
            if(sb.find(sa) == 0){
                return mycmp(sa, sb.substr(sb.find(sa) + sa.length()));
            }
            else{
                return sb < sa;
            }
        }
    }
};

