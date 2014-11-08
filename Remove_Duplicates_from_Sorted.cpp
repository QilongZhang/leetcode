/*************************************************************************
	> File Name: Remove_Duplicates_from_Sorted.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 18时34分37秒
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
        while(pre){
            if(pre->next == NULL || pre->next->val != pre->val){
                pt->next = pre;
                pt = pre; 
                pre = pre->next;
                pt->next = NULL;
            }
            else
                pre = pre->next;
        }
        return Head.next;
    }
};

int main(){
    ListNode Head(1);
    Solution st;
    st.deleteDuplicates(&Head);
    return 0;
}
