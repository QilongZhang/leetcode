/*************************************************************************
	> File Name: Valid_Binary_Search_Tree.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月13日 星期四 13时05分03秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
private:
    vector<int> vi;

public:
    bool isValidBST(TreeNode *root){
        visitBST(root);

        for(int pre = 0, cur = 1; cur < vi.size(); ++pre, ++cur){
            if(vi[pre] >= vi[cur]){
                return false;
            }
        }

        return true;
    }

private:
    void visitBST(TreeNode * root){
        if(root){
            visitBST(root->left);
            vi.push_back(root->val);
            visitBST(root->right);
        }
    }
};
