#include <draw_utils.h>

// root, left, right
std::queue<BTree*> getPreorder(BTree* root){
	std::queue<BTree*> traversalOrder;
	std::stack<BTree*> stack;

	stack.push(root);
	while (!stack.empty()){
		BTree *node = stack.top();
		stack.pop();
		traversalOrder.push(node);
		if (node->right != nullptr)
			stack.push(node->right);
		if (node->left != nullptr)
			stack.push(node->left);
	}
	return traversalOrder;
}

// left, root, right
std::queue<BTree*> getInorder(BTree* root){
	std::queue<BTree*> traversalOrder;
	std::stack<BTree*> stack;
	BTree *node = root;

	while (node != nullptr || !stack.empty()){
		while (node != nullptr){
			stack.push(node);
			node = node->left;
		}
		node = stack.top();
		stack.pop();
		traversalOrder.push(node);
		node = node->right;
	}
	return traversalOrder;
}

// left, right, root
std::queue<BTree*> getPostorder(BTree* root){
	std::queue<BTree*> traversalOrder;
	std::stack<BTree*> stack;
	BTree *node = root;
	BTree *prev = nullptr;

	while (node != nullptr || !stack.empty()){
		while (node != nullptr){
			stack.push(node);
			node = node->left;
		}
		node = stack.top();
		if (node->right == nullptr || node->right == prev){
			traversalOrder.push(node);
			stack.pop();
			prev = node;
			node = nullptr;
		} else {
			node = node->right;
		}
	}
	return traversalOrder;
}
