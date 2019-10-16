#include <iostream>
#include <limits.h>
using namespace std;

/*
对于一个给定的链表，返回环的入口节点，如果没有环，返回null
拓展：你能给出不利用额外空间的解法么？
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head && !head->next) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        bool flag = false;
        while(fast->next && fast->next->next){
        	slow = slow->next;
        	fast = fast->next->next;
        	if(slow == fast){
        		flag = true;
        		break;
        	}
        }
        if(!flag) return NULL;

        ListNode *p = head;
        while(1){
            if(p == slow) break;
            slow = slow->next;
            p = p->next;
        }
        
        return p;
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
	n4->next = n3;

    ListNode *ret = sol.detectCycle(head);
    if(!ret) cout << "it is NULL" << endl;
    else cout << ret->val << endl;
}

