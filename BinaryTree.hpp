#pragma once
#include "Node.hpp"
#include <vector>

class BinaryTree
{
public :
	BinaryTree();
	void insert(int value);
	void remove(int value);	
	std::vector<int> getInOrder();
	std::vector<int> getPreOrder();
	std::vector<int> getPostOrder();

private:
	std::vector<int> itensList;
	Node* root;
	Node* insertRecursive(Node* current, int value);	
	void inOrder(Node* current);
	void preOrder(Node* current);
	void postOrder(Node* current);
};

