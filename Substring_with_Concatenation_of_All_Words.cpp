/*************************************************************************
	> File Name: Substring_with_Concatenation_of_All_Words.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月30日 星期四 11时03分58秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution{
protected:
	vector<int> vi;
	unordered_map<string, int> msb;
	int Slen, Llen, Lsize;

protected:
	void Test(string &S, vector<string> &L, int start){
		unordered_map<string, int> msi;
		int k = 0, l = 0, len = 0;
		string str;
		for (k = start; k < Slen && start <= Slen - Llen*Lsize; k += Llen){
			str = S.substr(k, Llen);
			if (msb.find(str) == msb.end()){
				start = k + Llen;
				len = 0;
				msi.clear();
			}
			else if (msi[str] == msb[str]){
				for (l = start; str != S.substr(l, Llen); l += Llen){
					--msi[S.substr(l, Llen)];
					--len;
				}
				start = l + Llen;
			}
			else{
				++msi[str];
				++len;
			}
			if (len == Lsize){
				vi.push_back(start);
				k = start;
				start += Llen;
				len = 0;
				msi.clear();
			}
		}
	}

public:
	vector<int> findSubstring(string &S, vector<string> &L){
		Slen = S.length(), Llen = L[0].length(), Lsize = L.size();
		for (int i = 0; i < Lsize; ++i)		++msb[L[i]];
		for (int st = 0; st < Llen; ++st)	Test(S, L, st);
		return vi;
	}
};

int main(){
    Solution st;
    string str = "barfoothefoobarman";
    vector<string> vstr(2);
    vstr[0] = "foo";
    vstr[1] = "bar";
    vector<int> vi = st.findSubstring(str, vstr);
    for(int i = 0; i < vi.size(); ++i)
        cout<<vi[i]<<' ';
    return 0;
}
