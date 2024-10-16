#include "Node.h"

template <class T>
class BinarySearchTree
{
protected:
	Node<T>* root;
	void deleteTree(Node<T>* node);

public:
	BinarySearchTree();
	~BinarySearchTree();

	virtual void insertNode(T val) = 0;
	virtual void printPreOrder() = 0;
	virtual void printInOrder() = 0;
	virtual void printPostOrder() = 0;
	virtual void searchNode(T val) = 0;
	virtual void minimumNode() = 0;
	virtual void maximumNode() = 0;
	virtual void deleteNode(T val) = 0;

};

template<class T>
void BinarySearchTree<T>::deleteTree(Node<T>* node)
{
	if (node != nullptr)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(this->root);
}
