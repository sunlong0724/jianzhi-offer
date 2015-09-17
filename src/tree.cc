
#include <string>
#include <iostream>
#include <ctype.h>

using std::string;
using std::endl;
using std::cout;
using std::cin;

typedef struct BTNode{
	int nVal;
	BTNode *l,*r;
}BTNode,*BTree;

BTNode* createBTree(BTree* root){
	if (!*root){
		*root = (BTNode*)malloc(sizeof(BTNode));
	}

	BTNode* p = *root;
	cin >> p->nVal;
	cout << "Give it a left child node:"<<endl;
	createBTree(&(p->l));

	cout << "Give it a right child node:"<<endl;
	createBTree(&(p->r));
	return p;
}


int main(int argc, char* argv[]){
	int choice;

	do{
		cout << "Binary Tree" << endl;
		cout << "** Menu**" << endl;
		cout << "** **********************************************" << endl;
		cout << "** 1 Create a binary tree." << endl;
		cout << "** 2 PreOrder the binary tree." << endl;
		cout << "** 3 MidOrder the binary tree." << endl;
		cout << "** 4 " << endl;
		cout << "** 5 Get the leaf node number of the binary tree." << endl;
		cout << "** 6 Display the binary tree." << endl;
		cout << "** 7 Get all nodes of the binary tree." << endl;
		cout << "** 8 exit." << endl;
		cout << "** **********************************************" << endl;
		cout << "** Hi Buddy! Give me a choice." << endl;

		cin >> choice;
		cout << choice << endl;



	}while(choice < 8);

	cout << "exited!" << endl;
	return 0;
}
