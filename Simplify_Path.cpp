/*************************************************************************
	> File Name: Simplify_Path.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月06日 星期四 16时41分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
    string simplifyPath(string path){
        vector<string> vs;
        stack<int> si;
        string ret;
        int pos = 0;
        while((pos = path.find('/')) != string::npos){
            vs.push_back(path.substr(0, pos + 1));
            path = path.substr(pos + 1);
        }
        if(!path.empty())
            vs.push_back(path);
        for(int i = 0; i < vs.size(); ++i){
            if(vs[i]=="/" && si.empty())
                si.push(i);
            else if((vs[i] == "../" || vs[i] == "..") && si.size() != 1)
                si.pop();
            else if(vs[i] == "../" || vs[i] == "/" || vs[i] == "./" || vs[i] == "." || vs[i] == "..")
                continue;
            else
                si.push(i);
        }
        while(!si.empty()){
            ret.insert(0, vs[si.top()]);
            si.pop();
        }
        if(ret.size() > 1 && ret[ret.size() - 1] == '/')
            ret.pop_back();
        return ret;
    }
};

int main(){
    Solution st;
    string str = "///eHx/..";
    cout<<st.simplifyPath(str)<<endl;
    return 0;
}
