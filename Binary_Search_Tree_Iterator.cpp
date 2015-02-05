/*************************************************************************
	> File Name: Binary_Search_Tree_Iterator.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月05日 星期四 09时42分28秒
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class BSTIterator{
public:
    BSTIterator(TreeNode *root){
        sortBST(root);
    }

    bool hasNext(){
       return !(sTp.empty());
    }

    int next(){
        TreeNode * temp = sTp.top();
        sTp.pop();
        return temp->val;
    }

private:
    stack<TreeNode *> sTp;

private:
    void sortBST(TreeNode * root){
        if(!root){
            return;
        }
        sortBST(root->right);
        sTp.push(root);
        sortBST(root->left);
    }
};
