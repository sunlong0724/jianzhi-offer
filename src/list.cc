
#include <iostream>
#include <stdint.h>
using std::cout;
using std::endl;

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

int main(int argc, char* argv[]){
	ListNode *head = NULL;
	for (int i = 0; i < 100; ++i) 
		addNode(&head,i);


	printList(&head);

	removeNode(&head,50);

	printList(&head);

	deleteAll(&head);

	return 0;
}
