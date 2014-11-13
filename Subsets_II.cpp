/*************************************************************************
	> File Name: Subsets_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 03时41分42秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
protected:
    vector<vector<int> > vvi;
    vector<int> vi;

protected:
    void C(vector<int> &A, int k, int s, int c){
        if(c == k){
            vvi.push_back(vi);
            return;
        }
        int i = s;
        while(i < A.size() - k + c + 1){
            int identical = 1;
            for(int j = s + 1; j < A.size(); ++j)
                if(A[j] == A[s])
                    ++identical;
                else
                    break;
            if(identical > k - c)
                s += identical - k + c;
            vi.push_back(A[s]);
            C(A, k, s + 1, c + 1);
            vi.pop_back();
	        i += identical;
            s = i;
        }
    }

public:
    vector<vector<int> > subsetsWithDup(vector<int> &s){
	    sort(s.begin(), s.end());
        for(int i = 0; i <= s.size(); ++i)
            C(s, i, 0, 0);
        return vvi;
    }
};
