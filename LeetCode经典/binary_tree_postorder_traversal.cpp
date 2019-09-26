#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//不要用递归实现后序遍历
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	//正常后序遍历
    vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> ret;
    	if(root == NULL) return ret;
    
        stack<TreeNode *> ts;
        ts.push(root);
        TreeNode *pre = NULL;
        while(!ts.empty()){
        	TreeNode *top = ts.top();
        	if((!top->left && !top->right) || (pre && (pre == top->left || pre == top->right))){
        		ret.push_back(top->val);
        		ts.pop();
        		pre = top;
            }
            else{
            	if(top->right) ts.push(top->right);
            	if(top->left) ts.push(top->left);
            }

        }
        return ret;
    }

    //前序遍历 根->左->右 变成 根->右->左 结果再reverse一下
    vector<int> postorderTraversal2(TreeNode *root){
    	vector<int> ret;
    	if(!root) return ret;

    	stack<TreeNode *> ts;
    	ts.push(root);
    	while(!ts.empty()){
    		TreeNode *top = ts.top();
    		ret.push_back(top->val);
    		ts.pop();
    		if(top->left) ts.push(top->left);
    		if(top->right) ts.push(top->right);
    	}
    	reverse(ret.begin(), ret.end());
    	return ret;
    }

    //递归
    void postorder(TreeNode *root){
    	if(root == NULL) return;
    	if(root->left) postorder(root->left);    	
    	if(root->right) postorder(root->right);
    	cout << root->val << " ";
    }
};


int main(){
	TreeNode *n0 = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(3);
	TreeNode *n3 = new TreeNode(4);
	n0->left = n1;
	n0->right = n2;
	n2->left = n3;
	Solution sol;
	vector<int> ret = sol.postorderTraversal2(n0);
	for(auto i : ret){
		cout << i << " ";
	}
	cout << endl;
	//sol.postorder(n0);
}