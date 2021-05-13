#include <draw_utils.h>

BTree* createTree(int nLevels, int lower_bound, int upper_bound){
	if (nLevels-- == 0)
		return nullptr;
	BTree *root = new BTree((rand() + lower_bound) % upper_bound);

	if (nLevels < 2 && root->val % 2)
		root->left = createTree(nLevels, lower_bound, root->val);
	else if (nLevels < 2 && rand() % 2)
		root->right = createTree(nLevels, root->val, upper_bound);
	else {
		root->left = createTree(nLevels, lower_bound, root->val);
		root->right = createTree(nLevels, root->val, upper_bound);
	}
	return root;
}

void initCoords(BTree *node, int yLength, int xLength){
	xLength /= 2;
	if (node->left != nullptr){
		node->left->x = node->x - xLength;
		node->left->y = node->y + yLength;
		initCoords(node->left, yLength, xLength);
	}
	if (node->right != nullptr){
		node->right->x = node->x + xLength;
		node->right->y = node->y + yLength;
		initCoords(node->right, yLength, xLength);
	}
}

void resetVisited(BTree *root){
	std::stack<BTree*> stack;
	stack.push(root);
	while (!stack.empty()){
		BTree *node = stack.top();
		stack.pop();
		node->visited = false;
		if (node->left != nullptr)
			stack.push(node->left);
		if (node->right != nullptr)
			stack.push(node->right);
	}
}

