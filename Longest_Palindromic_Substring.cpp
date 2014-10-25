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
        int st=0, len=0;
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
                    if(dp[n][m] && m-n>len){
                        len = m-n;
                        st = n;
                    }
                }
            }
        }
        return s.substr(st, len+1);
    }   
};
