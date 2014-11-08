/*************************************************************************
	> File Name: Remove_Duplicates_from_Sorted_List_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 15时43分19秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
        ListNode Head(-1);
        ListNode *pre = head, *pt = &Head;
        bool mark = false;
        while(pre){
            if(pre->next == NULL || pre->val != pre->next->val){
                pt->next = pre;
                pt = pre;
                pre = pre->next;
                pt->next = NULL;
            }
            else{
                ListNode *post = pre->next;
                while(post && post->val == pre->val) post = post->next;
                pre = post;
            }
        }
        return Head.next;
    }
};
