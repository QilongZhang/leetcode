/*************************************************************************
	> File Name: Longest_Palindromic_Substring.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 15时14分00秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        bool dp[1000][1000];
        for(int i=0; i<s.size(); ++i){
            dp[i][i] = true;
            for(int j=i+1; j<s.size(); ++j)
                dp[i][j] = false;
        }
        for(int m=1; m < s.size(); ++m){
            for(int n=0; n < m; ++n){
                if(s[m]==s[n]){
                    if(n+1 == m)
                        dp[n][m] = true;
                    else if(dp[n+1][m-1])
                        dp[n][m] = true;
                }
            }
        }
        int len = -1, st = -1;
        for(int p=0; p<s.size(); ++p){
            for(int q=s.size()-1; q>=p; --q){
                if(q-p<len)
                    break;
                if(dp[p][q]){
                    if(q-p>len){
                        st=p;
                        len=q-p;
                    }
                    break;
                }
            }    
        }
        return s.substr(st, len+1);
    }   
};
