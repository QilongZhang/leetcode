/*************************************************************************
	> File Name: HDU3068.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 22时11分24秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestPdr(vector<char>& vc){
    vector<int> rda(vc.size(), 0);
    int ret = 0;
    int i, j, k;
    for(i=1, j=0; i<vc.size();){
        while((i-j-1) >=0 && (i+j+1) < vc.size() && vc[i-j-1] == vc[i+j+1]) ++j;
        rda[i]=j;
        for(k=1; k<=j && rda[i-k] != rda[i] - k; ++k)  
            rda[i+k] = min(rda[i-k], rda[i] - k);
        i += k;
        j = max(j-k, 0);
    }
    for(i=0; i<vc.size(); ++i) ret = max(ret, rda[i]);
    
    return ret;
}


int main(){
    string str;
    while(cin>>str){
        vector<char> vc;
        for(int pt=0; pt<str.size(); ++pt){
            vc.push_back('#');
            vc.push_back(str[pt]);
        }
        vc.push_back('#');
        cout<<longestPdr(vc)<<endl;
    }
    return 0;
}
