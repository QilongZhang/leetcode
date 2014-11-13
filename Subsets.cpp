/***************mZght4534@gmail.com
	> Created Time: 2014年11月14日 星期五 02时32分46秒
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
        for(int i = s; i < A.size() - k + c + 1; ++i){
            vi.push_back(A[i]);
            C(A, k, i + 1, c + 1);
            vi.pop_back();
        }
    }

public:
    vector<vector<int> > subsets(vector<int> &s){
        sort(s.begin(), s.end());
        for(int i = 0; i <= s.size(); ++i)
            C(s, i, 0, 0);
        return vvi;
    }
};
