/*************************************************************************
	> File Name: Unique_Binary_Search_Trees_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 04时44分11秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<TreeNode *> generateTrees(int n){
        return gTrees(1, n);
    }

private:
    vector<TreeNode *> gTrees(int st, int ed){
        vector<TreeNode *> vT;
        
        if(st > ed){
            vT.push_back(NULL);
            return vT;
        }
        
        for(int i = st; i <= ed; ++i){
            vector<TreeNode *> leftvT = gTrees(st, i-1);
            vector<TreeNode *> rightvT = gTrees(i+1, ed);
            for(int k = 0; k < leftvT.size(); ++k){
                for(int l = 0; l < rightvT.size(); ++l){
                    TreeNode * head= new TreeNode(i);
                    head->left = leftvT[k];
                    head->right = rightvT[l];
                    vT.push_back(head);
                }
            }
        }

        return vT;
    }
};
