/*************************************************************************
	> File Name: Permutation_Sequence.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 12时35分45秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    string getPermutation(int n, int k){
        int table[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int istr[10] = {0};
        int cnt = n;
        while(k){
            istr[n] = k%table[n-1]?k/table[n-1]+1:k/table[n-1];
            k = k%table[n-1];
            --n;
        }
        for(int i = n; i >= 1; --i)
            istr[i] = i;
        bool mark[10] = {false};
        string str = "";
        for(int j = cnt; j >= 1; --j){
            int k = 0;
            for(int l = 1; l <= cnt; ++l){
                if(mark[l] == false){
                    ++k;
                    if(k == istr[j]){
                        str += char('0' + l);
                        mark[l] = true;
                        break;
                    }
                }
            }
        }
        return str;
    }
};

int main(){
    Solution st;
    cout<<st.getPermutation(4, 6);
    return 0;
}
