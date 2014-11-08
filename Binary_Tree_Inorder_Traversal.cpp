/*************************************************************************
	> File Name: Binary_Tree_Inorder_Traversal.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 18时29分11秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) ; val(x), left(NULL), right(NULL){}
};

class Solution{
protected:
    void IT(TreeNode *root, vector<int> &vi){
        if(root == NULL)
            return;
        IT(root->left, vi);
        vi.push_back(root->val);
        IT(root->right, vi);
    }

public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> vi;
        IT(root, vi);
        return vi;
    }
};
