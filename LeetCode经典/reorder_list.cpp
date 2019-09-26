#include <iostream>
#include <limits.h>
using namespace std;

/*
将给定的单链表L： L 0→L 1→…→L n-1→L n,
重新排序为： L 0→L n →L 1→L n-1→L 2→L n-2→…
要求使用原地算法，并且不改变节点的值
例如：
对于给定的单链表{1,2,3,4}，将其重新排序为{1,4,2,3}.

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        
    }
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(1);
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(3);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(5);
	
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	
	sol.reorderList(head);
	sol.print(head);
}
