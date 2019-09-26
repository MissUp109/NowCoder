#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//不要用递归实现前序遍历
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(!root) return ret;

        stack<TreeNode *> mstack;
        mstack.push(root);
        while(!mstack.empty()){
        	TreeNode *top = mstack.top();
        	ret.push_back(top->val);
        	mstack.pop();
        	if(top->right) mstack.push(top->right);
        	if(top->left) mstack.push(top->left);
        }
        return ret;
    }

    void preorder(TreeNode *root){
    	if(!root) return;
    	cout << root->val << " ";
    	preorder(root->left);
    	preorder(root->right);
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
	sol.preorder(n0);
	vector<int> ret = sol.preorderTraversal(n0);
	for(auto i : ret){
		cout << i << " ";
	}
	cout << endl;
	//sol.postorder(n0);
}
