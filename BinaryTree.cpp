#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

void BinaryTree::insert(int value) {
	root = insertRecursive(root, value);
}
void BinaryTree::remove(int value) {
}
std::vector<int> BinaryTree::getInOrder() {
	std::vector<int> list;
	
	if (itensList.size() > 0)
		itensList.clear();
	inOrder(root);

	list = itensList;
	return list;
}
std::vector<int> BinaryTree::getPreOrder() {
	std::vector<int> list;
	
	if (itensList.size() > 0)
		itensList.clear();

	preOrder(root);
	list = itensList;
	return list;
}
std::vector<int> BinaryTree::getPostOrder() {
	std::vector<int> list;
	
	if(itensList.size() > 0)
		itensList.clear();

	postOrder(root);
	list = itensList;
	return list;
}
//métodos privados	
Node* BinaryTree::insertRecursive(Node* current, int value) {
	if (current == nullptr) {
		return new Node(value);
	}

	if (value < current->value) {
		current->left = insertRecursive(current->left, value);
	}
	else if (value > current->value) {
		current->right = insertRecursive(current->right, value);
	}

	return current;
}
void BinaryTree::inOrder(Node* current) {

	if (current != nullptr) {
		inOrder(current->left);
		itensList.push_back(current->value);
		inOrder(current->right);
	}
}
void BinaryTree::preOrder(Node* current) {
	if (current != nullptr) {
		itensList.push_back(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}
}
void BinaryTree::postOrder(Node* current) {
	if (current != nullptr) {
		postOrder(current->left);
		postOrder(current->right);
		itensList.push_back(current->value);
	}
}
