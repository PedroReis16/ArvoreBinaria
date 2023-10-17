#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "TreeInfos.hpp"
#include "BinaryTree.hpp"




std::vector<int> getRandomNumbers(int size) {
	std::vector<int> saida;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>intDistribution(1, 1000000);

	for (int i = 0; i < size; i++) {
		int numero = intDistribution(gen);
		saida.push_back(numero);
	}

	return saida;
}
TreeInfo* action(int size) {
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	TreeInfo* info = new TreeInfo();
	BinaryTree* tree = new BinaryTree();
	std::string description;

	if (size == 1000)
		description = "1000 elementos";
	else if (size == 3000)
		description = "3000 elementos";
	else
		description = "5000 elementos";

	info->Description = description;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < getRandomNumbers(size).size(); i++) {
		tree->insert(i);
	}
	end = std::chrono::steady_clock::now();

	info->InsertionTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	info->Depth = tree->depth();
	info->Height = tree->height();

	std::vector<int> inOrder = tree->getInOrder();
	std::vector<int> preOrder = tree->getPreOrder();
	std::vector<int> posOrder = tree->getPostOrder();

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < inOrder.size(); i++) {
		std::cout << inOrder[i] << " ";
	}
	end = std::chrono::steady_clock::now();

	info->ReadInOrder = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < preOrder.size(); i++) {
		std::cout << preOrder[i] << " " << std::endl;
	}
	end = std::chrono::steady_clock::now();

	info->ReadPreOrder = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < posOrder.size(); i++) {
		std::cout << posOrder[i] << " " << std::endl;
	}
	end = std::chrono::steady_clock::now();

	info->ReadPosOrder = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();


	return info;
}


int main()
{
	TreeInfo* thousandInfo = action(1000);
	TreeInfo* treeInfo = action(3000);
	TreeInfo* fiveInfo = action(5000);


	thousandInfo->getInfos();
	std::cout << std::endl;

	treeInfo->getInfos();
	std::cout << std::endl;

	fiveInfo->getInfos();
	std::cout << std::endl;
}


