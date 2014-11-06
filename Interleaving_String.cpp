/*************************************************************************
	> File Name: Interleaving_String.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月06日 星期四 08时41分35秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
protected:
    bool ISL(string &s1, string &s2, string &s3, vector<vector<bool> > &vb, int p1, int p2, int p3){
        if(s1[p1] == '\0' && s2[p2] == '\0' && s3[p3] == '\0')
            return true;
        else if(s3[p3] == '\0' || vb[p3][p1])
            return false;
        vb[p3][p1] = true;

        bool m1 = false;
        while(s3[p3] != '\0'){
            if(s3[p3] == s1[p1]){
                m1 = ISL(s1, s2, s3, vb, p1+1, p2, p3+1);
                if(m1)
                    return true;
            }
            if(s3[p3] == s2[p2])
                ++p2, ++p3;
            else
                return false;
        }
        return ISL(s1, s2, s3, vb, p1, p2, p3);
    }

public:
    bool isInterleave(string s1, string s2, string s3){
        vector<vector<bool> > vb(s3.length(), vector<bool>(s1.length(), false));
        return ISL(s1, s2, s3, vb, 0, 0, 0);
    }
};


int main(){
    Solution st;
    string s1 = "aabc", s2 = "abad", s3 = "aabcabad";
    if(st.isInterleave(s1, s2, s3))
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
    return 0;
}
