#include "BinarySearchTree.h"

template <class T>
class MyBinarySearchTree : public BinarySearchTree<T>
{
private:
	Node<T>* insertHelper(Node<T>* node, T val);
	void preOrderHelper(Node<T>* node);
	void inOrderHelper(Node<T>* node);
	void postOrderHelper(Node<T>* node);
	bool searchHelper(Node<T>* node, T val);
	Node<T>* minimumHelper(Node<T>* node);
	Node<T>* maximumHelper(Node<T>* node);
	Node<T>* deleteHelper(Node<T>* node, T val);

public:
	void insertNode(T val) override;
	void printPreOrder() override;
	void printInOrder() override;
	void printPostOrder() override;
	void searchNode(T val) override;
	void minimumNode() override;
	void maximumNode() override;
	void deleteNode(T val) override;

};

template<class T>
Node<T>* MyBinarySearchTree<T>::insertHelper(Node<T>* node, T val)
{
	if (node == nullptr)
	{
		return node = new Node<T>(val);
	}
	else if (val < node->data)
	{
		node->left = insertHelper(node->left, val);
	}
	else if (val > node->data)
	{
		node->right = insertHelper(node->right, val);
	}
	return node;
}

template<class T>
void MyBinarySearchTree<T>::preOrderHelper(Node<T>* node)
{
	if (node != nullptr)
	{
		cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
	}
}

template<class T>
void MyBinarySearchTree<T>::inOrderHelper(Node<T>* node)
{
	if (node != nullptr)
	{
		inOrderHelper(node->left);
		cout << node->data << " ";
		inOrderHelper(node->right);
	}
}

template<class T>
void MyBinarySearchTree<T>::postOrderHelper(Node<T>* node)
{
	if (node != nullptr)
	{
		postOrderHelper(node->left);
		postOrderHelper(node->right);
		cout << node->data << " ";
	}
}

template<class T>
bool MyBinarySearchTree<T>::searchHelper(Node<T>* node, T val)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (val < node->data)
	{
		searchHelper(node->left, val);
	}
	else if (val > node->data)
	{
		searchHelper(node->right, val);
	}
	else if (val == node->data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
Node<T>* MyBinarySearchTree<T>::minimumHelper(Node<T>* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->left != nullptr)
	{
		node = node->left;
	}
	return node;
}

template<class T>
Node<T>* MyBinarySearchTree<T>::maximumHelper(Node<T>* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

template<class T>
inline Node<T>* MyBinarySearchTree<T>::deleteHelper(Node<T>* node, T val)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (val < node->data)
	{
		node->left = deleteHelper(node->left, val);
	}
	else if (val > node->data)
	{
		node->right = deleteHelper(node->right, val);
	}
	else
	{
		if (node->left == nullptr)
		{
			return node->right;
		}
		else if (node->right == nullptr)
		{
			return node->left;
		}
		
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;

		node->right = deleteHelper(node->right, node->data);
	}
	return node;
}

template<class T>
void MyBinarySearchTree<T>::insertNode(T val)
{
	this->root = insertHelper(this->root, val);
}

template<class T>
void MyBinarySearchTree<T>::printPreOrder()
{
	preOrderHelper(this->root);
	cout << endl;
}

template<class T>
void MyBinarySearchTree<T>::printInOrder()
{
	inOrderHelper(this->root);
	cout << endl;
}

template<class T>
void MyBinarySearchTree<T>::printPostOrder()
{
	postOrderHelper(this->root);
	cout << endl;
}

template<class T>
void MyBinarySearchTree<T>::searchNode(T val)
{
	if (searchHelper(this->root,val))
	{
		cout << "Value " << val << " found." << endl;
	}
	else
	{
		cout << "Value " << val << " not found." << endl;
	}
}

template<class T>
void MyBinarySearchTree<T>::minimumNode()
{
	Node<T>* min = minimumHelper(this->root);
	if (this->root == nullptr)
	{
		cout << "Tree is empty." << endl << endl;
		return;
	}
	cout << "Minimum value is: " << min->data << endl;
	cout << endl;
}

template<class T>
void MyBinarySearchTree<T>::maximumNode()
{
	Node<T>* max = maximumHelper(this->root);
	if (this->root == nullptr)
	{
		cout << "Tree is empty." << endl << endl;
		return;
	}
	cout << "Maximum value is: " << max->data << endl;
	cout << endl;
}

template<class T>
void MyBinarySearchTree<T>::deleteNode(T val)
{
	deleteHelper(this->root, val);
	cout << "Deleted value is " << val << endl;
	cout << endl;
}
