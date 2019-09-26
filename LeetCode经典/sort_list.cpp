#include <iostream>
using namespace std;

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
        ListNode* tail = head;
        ListNode* cur = tail->next;
        while(cur){
        	if(cur->val >= tail->val){
        		tail = cur;
        		cur = cur->next;
        	}
        	else{
        		ListNode* cnxt = cur->next;
        		if(head == tail){  			
        			cur->next = head;
        			head->next = cnxt;
        			head = cur;
        		}
        		else if(head->val > cur->val){
        			cur->next = head;
        			tail->next = cnxt;
        			head = cur;
        		}
        		else{
        			ListNode* tmp = head;
        			while(tmp->next){
        				if(tmp->next->val > cur->val) break;
        				tmp = tmp->next;
        			}
        			cur->next = tmp->next;
        			tmp->next = cur;
        			tail->next = cnxt;
        		}
        		cur = cnxt;
        	}
        	//print(head);
        }
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
	
	//head->next = n1;
	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = NULL;
	
	//head = sol.sortList(head);
	//sol.sortList(head);
	sol.print(head);
}