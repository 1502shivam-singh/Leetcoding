#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(TreeNode* left, TreeNode* right, int val) : left(left), right(right), val(val) {};
	TreeNode() : left(nullptr), right(nullptr) {};
	TreeNode(int val) : left(nullptr), right(nullptr), val(val) {};
};

vector<int> vec;

vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> stack;
	stack.push(root);
	unordered_map<TreeNode*, int> hset;

	while (!stack.empty())
	{
		if (stack.top()->left != nullptr && !hset[stack.top()->left])
		{
			stack.push(stack.top()->left);
		}
		else
		{
			TreeNode* ptr = stack.top();
			hset[ptr] = 1;
			vec.push_back(ptr->val);
			stack.pop();
			if (ptr->right != nullptr)
			{
				stack.push(ptr->right);
			}
		}
	}
	return vec;
}

ostream& operator<<(ostream& stream, vector<int> vec) {
	stream << "[ ";
	for (auto it : vec) {
		stream << it<<" ";
	}
	stream << "]";
	return stream;
}

int main() {
	TreeNode start(1), left(0), right(3);
	start.left = &left;
	start.right = &right;
	vector<int> store = inorderTraversal(&start);
	cout << store;
	std::cin.get();
}
