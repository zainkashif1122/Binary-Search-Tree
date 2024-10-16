#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;

	Node(T d);
};

template<class T>
Node<T>::Node(T d)
{
	data = d;
	left = nullptr;
	right = nullptr;
}