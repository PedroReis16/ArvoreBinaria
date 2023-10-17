#pragma once
#include <string>
#include <iostream>
class TreeInfo
{
public:
	std::string Description;
	double InsertionTime;
	int Depth;
	int Height;
	int ReadInOrder;
	int ReadPreOrder;
	int ReadPosOrder;
	void getInfos();
};