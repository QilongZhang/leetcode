/*************************************************************************
	> File Name: Word_LadderII.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年09月20日 星期六 20时57分12秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict){
        queue<string> vs;
        unordered_set<string> used;
        string stm, tstm;
        int ret, p, P, ed;
        ret = p = P = ed = 0;
        vs.push(start);
        if (dict.find(end) == dict.end()){
            dict.insert(end);            
        }
        while (vs.size()){
            stm = vs.front();
            vs.pop();
            if (p > P){
                ++ret;
                P = ed;    
            }
            ++p;
            for (int i = 0; i < stm.length(); ++i){
                for (char ch = 'a'; ch <= 'z'; ++ch){
                    tstm = stm;
                    tstm[i] = ch;
                    if (used.find(tstm) != used.end()){
                        continue;                    
                    }
                    if (dict.find(tstm) != dict.end()){
                        if (tstm == end){
                            return ret + 2;                        
                        }
                        vs.push(tstm);
                        used.insert(tstm);
                         ++ed;                    
                    }      
                }       
            }   
        }
        return 0;    
    }
};
