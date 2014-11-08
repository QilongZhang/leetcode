/*************************************************************************
	> File Name: Same_Tree.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 17时12分25秒
 ************************************************************************/

#include <iostream>

using namespace std;

class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
