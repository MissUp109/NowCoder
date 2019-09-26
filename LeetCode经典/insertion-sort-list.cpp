#include <iostream>
#include <limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//相比下面的方法更简单，但是在某些特殊情况会慢一些，比如cur比tail要大
class Solution {
public:
	void print(ListNode *head){
		while(head){
			cout << head->val << "->";
			head = head->next;
		}
		cout << endl;
	}

     ListNode* insertionSortList(ListNode *head) {
        //哑节点
        ListNode *dumy = new ListNode(INT_MAX);
        ListNode *cur = head;
        ListNode *pre = dumy;
        while (cur != NULL) {
            //保存当前节点下一个节点
            ListNode *next = cur->next;
            pre = dumy;
            //寻找当前节点正确位置的一个节点
            while (pre->next != NULL && pre->next->val < cur->val) {
                pre = pre->next;
            }
            //将当前节点加入新链表中
            cur->next = pre->next;
            pre->next = cur;
            //处理下一个节点
            cur = next;
        }
        return dumy->next;
    }
};

/*
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
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
*/

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
	n4->next = NULL;
	
	head = sol.insertionSortList(head);
	sol.print(head);
}