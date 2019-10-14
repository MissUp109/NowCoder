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
    void reverseList(ListNode* &head){//注意'&'
        if(!head || !head->next) return;
        ListNode *cur = head->next;
        head->next = NULL;
        ListNode *tmp = NULL;
        while(cur){
            tmp = cur->next;
            cur->next = head;
            head = cur;
            cur = tmp;        
        }
    }

    void reverse(ListNode * &head){//新建头节点方法
        ListNode *a = new ListNode(0);
        ListNode *p = head;
        ListNode *temp = NULL;
        while(p){
            cout << p->val << " ";
            temp = p->next;
            p->next = a->next;
            a->next = p;
            p = temp;
        }
        cout << endl;
        head = a->next;
    }

    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next){
        	return;
        }

        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
        	slow = slow->next;
        	fast = fast->next->next;
        }

        cout << "mid: " << slow->next->val << endl;

        ListNode *p = head;
        ListNode *q = slow->next;
        reverseList(q);

        ListNode *tmp = NULL;
        bool flag = true;
        while(p && q){
        	cout << "p: " << p->val << ", q: " << q->val << ", flag: " << flag << endl;
        	if(flag){
        		tmp = p->next;
        		p->next = q;
        		p = tmp;
            }
        	else{
        		tmp = q->next;
        		q->next = p;
        		q = tmp;
        	}
        	flag = !flag;

        }
        if(p) p->next = NULL;
        if(q) q->next = NULL;
    }

    void print(ListNode *head){
    	while(head){
    		cout << head->val << " -> ";
    		head = head->next;
    	}
    	cout << endl;
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
	
    //sol.reverse(head);
    //sol.reverseList(head);
	sol.reorderList(head);
	sol.print(head);
}
