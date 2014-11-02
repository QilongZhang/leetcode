/*************************************************************************
	> File Name: Search_for_a_Range.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月02日 星期日 12时13分27秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(int A[], int n, int target){
        int st = -1, ed = -1;
        int s, e, m;
        s = 0, e = n - 1, m = (s + e)/2;
        while(s <= e){
            if(A[s] == target){
                st = s;
                break;
            }
            else if(s == e)
                break;
            m = (s + e)/2;
            if(A[m] >= target)
                e = m;
            else
                s = m + 1;
        }
        s = 0, e = n - 1;
        while(s <= e && st != -1){
            if(A[e] == target){
                ed = e;
                break;
            }
            m = (s + e)/2 + 1;
            if(A[m] > target)
                e = m - 1;
            else
                s = m;
        }
        vector<int> vi;
        vi.push_back(st);
        vi.push_back(ed);
        return vi;
    }
};
