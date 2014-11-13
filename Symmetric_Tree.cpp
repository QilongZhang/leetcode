/*************************************************************************
	> File Name: Symmetric_Tree.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月13日 星期四 12时55分54秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
protected:
    bool IS(TreeNode *l, TreeNode *r){
        if(l == NULL && r == NULL)
            return true;
        else if(l == NULL || r == NULL)
            return false;
        else if(l->val != r->val)
            return false;
        else 
            return IS(l->left, r->right) && IS(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode *root){
        if(root == NULL)
            return true;
        return IS(root->left, root->right);
    }
};
