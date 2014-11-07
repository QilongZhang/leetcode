/*************************************************************************
	> File Name: Restore_IP_Addresses.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月06日 星期四 22时26分57秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution{
protected:
    vector<string> vs;

protected:
    void RIA(string &s, int pos, int id, string str){
        int nid;
        string sid;
        if(id == 4){
            sid = s.substr(pos);
            if(sid[0] == '0' && sid.size() > 1)
                return;
            sscanf(sid.c_str(), "%d", &nid);
            if(nid <= 255){
                str += sid;
                vs.push_back(str);
            }
            return ;
        }
        for(int i = 1; i <= 3 && pos + i < (int)s.length(); ++i){
            sid = s.substr(pos, i);
            sscanf(sid.c_str(), "%d", &nid);
            if(nid > 255)
                break;
            RIA(s, pos + i, id + 1, str + sid + ".");
            if(s[pos] == '0')
                break;
        }
    }

public:
    vector<string> restoreIpAddresses(string s){
        RIA(s, 0, 1, "");
        return vs;
    }
};

