/*************************************************************************
	> File Name: Repeated_DNA_Sequences.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月08日 星期日 18时12分53秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

class Solution{
public:
    vector<string> findRepeatedDnaSequences(string s){
        vector<string> vs;
        unordered_map<unsigned, size_t> mus;
        vector<bool> vb(s.length(), false);
        unsigned value = 0;

        if(s.length() < 10){
            return vs;
        }

        for(int pt = 0; pt < 10; ++pt){
            value *= 4;
            switch(s[pt]){
                case 'A': {value += 0; break;}
                case 'C': {value += 1; break;}
                case 'G': {value += 2; break;}
                case 'T': {value += 3; break;}
            }
        }
        mus.insert(std::pair<unsigned, size_t>(value, 0));


        for(size_t ed = 10; ed < s.length(); ++ed){
            unsigned pva;
            switch(s[ed - 10]){
                case 'A': {pva = 0; break;}
                case 'C': {pva = pow(4, 9); break;}
                case 'G': {pva = 2 * pow(4, 9);  break;}
                case 'T': {pva = 3 * pow(4, 9); break;}
            }
            value = (value - pva) * 4;
            switch(s[ed]){
                case 'A': break;
                case 'C': {value += 1; break;}
                case 'G': {value += 2; break;}
                case 'T': {value += 3; break;}
            }
            if(mus.find(value) != mus.end() && !vb[mus.find(value)->second]){
                vs.push_back(s.substr(mus.find(value)->second, 10));
                vb[mus.find(value)->second] = true;
            }
            else{
                mus.insert(std::pair<unsigned, size_t>(value, ed - 9));
            }
        }

        return vs;
    }
};

