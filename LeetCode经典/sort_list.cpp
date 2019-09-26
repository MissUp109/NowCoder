#include <iostream>
using namespace std;

//在O(n log n)的时间内使用常数级空间复杂度对链表进行排序。
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void print(ListNode *head){
		while(head){
			cout << head->val << "->";
			head = head->next;
		}
		cout << endl;
	}

    ListNode *sortList(ListNode *head) {
    	if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l1 = head, *l2 = slow->next;
        slow->next = NULL;
        l1 = sortList(l1);
        l2 = sortList(l2);
        head = mergeList(l1, l2);
        return head;
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *head = NULL;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }

        ListNode *tail = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if(l1) tail->next = l1;
        if(l2) tail->next = l2;

        return head;
    }
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(7);
	ListNode* n1 = new ListNode(5);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(3);
	
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	head = sol.sortList(head);
	sol.print(head);
}