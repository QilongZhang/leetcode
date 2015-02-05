/*************************************************************************
	> File Name: Convert_Sorted_List_to_Binary_Search_Tree.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月05日 星期四 10时47分56秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode * sortedListToBST(ListNode *head){
        if(!head){
            return NULL;
        }

        vector<int> vi;
        while(head){
            vi.push_back(head->val);
            head = head->next;
        }

        return array2BST(vi, 0, vi.size() - 1);
    }

private:
    TreeNode * array2BST(vector<int> & vi, int st, int ed){
        if(st > ed){
            return NULL;
        }
        int mid = (st + ed) / 2;
        TreeNode * head = new TreeNode(vi[mid]);
        head->left = array2BST(vi, st, mid - 1);
        head->right = array2BST(vi, mid + 1, ed);
        return head;
    }
};
