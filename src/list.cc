
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
	ListNode* p = *head;

	while(p->next)
		p = p->next;

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->nVal = val;
	node->next = NULL;
	p->next = node;

}

int main(int argc, char* argv[]){
	ListNode *head = NULL;
	for (int i = 0; i < 100; ++i) 
		addNode(&head,i);

	ListNode* p = head->next;
	while(p){
		cout << p->nVal << " ";
		p = p->next;
	}
	cout << endl;

	p = head;
	while(p) {
		ListNode* tmp = p->next;
		delete p;
		p = tmp;
	}
	return 0;
}
