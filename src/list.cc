
#include <iostream>
#include <stdint.h>
#include <vector>
#include <iterator>
#include <stack>

using std::cout;
using std::endl;
using std::vector;

typedef struct ListNode{
	int nVal;
	struct ListNode* next;
}ListNode;

/**
 * @brief addNode add a ListNode
 *
 * @param head
 * @param val
 */
void addNode(ListNode** head, int val) {
	if (*head == NULL){
		*head = (ListNode*)malloc(sizeof(ListNode));
		(*head)->next = NULL;
	}
	ListNode* p = (*head);

	while(p->next)
		p = p->next;

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->nVal = val;
	node->next = NULL;
	p->next = node;

}

void removeNode(ListNode** head, int val) {
	if (*head == NULL){
		return;
	}

	ListNode* last = (*head);
	ListNode* p = last->next;
	while(p){
		if (p->nVal == val){
			last->next = p->next;	
			delete p;
		}
		last = p;
		p = p->next;

	}
}

void deleteAll(ListNode** head) {
	ListNode* p = *head;
	while(p) {
		ListNode* tmp = p->next;
		delete p;
		p = tmp;
	}
}

void printList(ListNode** head) {
	ListNode* p = (*head)->next;
	while(p){
		cout << p->nVal << " ";
		p = p->next;
	}
	cout << endl;
}


/**
 * @brief printReverseList2 don't need the head node!!!
 *
 * @param head
 */
void printReverseList2(ListNode** head) {
	ListNode* p = *head;
	if (!p->next){
		cout << p->nVal << " ";
		return;
	}

	printReverseList2(&(p->next));
	cout << p->nVal << " ";
}

void printReverseList(ListNode** head) {
#if 0
	vector<ListNode*> v;
	ListNode* p = (*head)->next;
	while(p){
		v.push_back(p);
		p = p->next;
	}

	/* iterator
	for (auto a = v.rbegin();a != v.rend(); ++a) 
		cout << (*a)->nVal << " ";
	cout << endl;
	*/

	// vector interface
	for (auto a : v){
		cout << v.back()->nVal << " ";
		v.pop_back();
	}
	cout << endl;
#endif

	using std::stack;
	stack<ListNode*> s;
	ListNode* p = (*head)->next;
	while(p){
		s.push(p);
		p = p->next;
	}

	while(!s.empty()){
		cout << s.top()->nVal << " ";
		s.pop();
	}
	cout << endl;
}

int main(int argc, char* argv[]){
	ListNode *head = NULL;
	for (int i = 0; i < 100; ++i) 
		addNode(&head,i);


//	printList(&head);

//	printReverseList(&head);

//	removeNode(&head,50);

	printList(&head);

//	printReverseList(&head);

	printReverseList2(&(head->next));

	deleteAll(&head);

	return 0;
}
