/*************************************************************************
	> File Name: Multiply_Strings.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月03日 星期一 14时05分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
        vector<int> n1(num1.size()), n2(num2.size()), ans(num1.length() + num2.length(), 0);
        string str;
        int i, j, k = num1.length() + num2.length() - 1;
        for(i = 0; i < num1.length(); ++i)
            n1[n1.size() - i - 1] = num1[i] - '0';
        for(i = 0; i < num2.length(); ++i)
            n2[n2.size() - i - 1] = num2[i] - '0';
        for(i = 0; i < n1.size(); ++i)
            for(j = 0; j < n2.size(); ++j)
                ans[j + i] += n2[j] * n1[i];
        for(i = 1; i <= num1.length() + num2.length() - 1; ++i){
            ans[i] += ans[i-1]/10;
            ans[i-1] = ans[i-1]%10;
        }
        while(ans[k] == 0) --k;
        while(k >= 0) str.push_back(ans[k--] + '0');
        if(str.length())
            return str;
        else
            return string("0");
    }
};

int main(){
    Solution st;
    string s1 = "21", s2 = "00";
    cout<<st.multiply(s1, s2);
    return 0;
}
