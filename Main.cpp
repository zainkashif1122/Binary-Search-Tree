#include "MyBinarySearchTree.h"

int main()
{
	MyBinarySearchTree <int>bst;

	while (true)
	{
		cout << "Menu: " << endl;
		cout << "1. Insert a value" << endl;
		cout << "2. Print pre order" << endl;
		cout << "3. Print in order" << endl;
		cout << "4. Print post order" << endl;
		cout << "5. Search value" << endl;
		cout << "6. Search minimum value" << endl;
		cout << "7. Search maximum value" << endl;
		cout << "8. Delete a value" << endl;
		cout << "9. Exit program" << endl;

		int value;
		int choice;

		cout << endl << "Enter your option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter value: ";
			cin >> value;
			bst.insertNode(value);
			cout << endl;
			break;

		case 2:
			bst.printPreOrder();
			cout << endl;
			break;

		case 3:
			bst.printInOrder();
			cout << endl;
			break;

		case 4:
			bst.printPostOrder();
			cout << endl;
			break;

		case 5:
			cout << "Enter the value you want to search: ";
			cin >> value;
			bst.searchNode(value);
			cout << endl;
			break;

		case 6:
			bst.minimumNode();
			break;

		case 7:
			bst.maximumNode();
			break;

		case 8:
			cout << "Enter the value you want to delete: ";
			cin >> value;
			bst.deleteNode(value);
			break;

		case 9:
			cout << "Exiting the program." << endl;
			cout << endl;
			return 0;

		default:
			cout << "Enter number of the above given options." << endl;
			cout << endl;
			break;

		}
	}

	return 0;
}