#define CURRENT 0
#include <vector>

#if CURRENT
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
struct BinaryNode
{
	int data = 0;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;
	BinaryNode(int data) { this->data = data; }
	
};
typedef struct BinaryNode BinaryNode;

int FindMax(const BinaryNode *root)
{
	if (root->left == nullptr)
		return root->data;
	
	return root->data + std::max(FindMax(root->left), FindMax(root->right));
}

int main()
{
	std::fstream file;
	std::string row, token;
	file.open(R"x(Source Files/18.txt)x");
	
	std::getline(file, row);
	auto *root = new BinaryNode(stoi(row));
	
	std::vector<BinaryNode*> prev = {root};
	while (std::getline(file, row)) // divide into rows
	{
		std::stringstream ss(row); // tokenize the current row
		std::vector<BinaryNode*> current;
		while (std::getline(ss, token, ' ')) // for every token
		{
			auto *bn = new BinaryNode(stoi(token));
			current.push_back(bn); // add the current binary node token
		}
		for (int i = 0; i < prev.size(); ++i) // add the connections for all the new tokens
		{
			prev.at(i)->left = current.at(i);
			prev.at(i)->right = current.at(i + 1);
		}
		prev = current; // jump forward
	}
	std::cout << FindMax(root);
	std::cin.get();
}

#endif