#include <iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
};

void createList(ListNode* pHead)
{
	ListNode* p = pHead;
	for (int i = 0;i<10;i++)
	{
		ListNode* pNewNode = new ListNode;
		pNewNode->data = i+1;
		pNewNode->next = nullptr;
		p->next = pNewNode;
		p = pNewNode;
	}
}

ListNode* reverseList(ListNode* pHead)
{
	ListNode *p, *q;
	ListNode *t = nullptr;
	p = pHead;
	if (p->next == nullptr || p->next->next == nullptr)
	{
		return pHead;
	}
	p = pHead->next;
	q = pHead->next->next;
	while (q != nullptr)
	{
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}
	pHead->next->next = nullptr;
	pHead->next = p;
	return pHead;
}


void showList(ListNode* pHead)
{
	ListNode* showList = pHead->next;
	while (showList != nullptr)
	{
		std::cout << showList->data << std::endl;
		showList = showList->next;
	}
}

int main()
{
	ListNode* head = nullptr;
	head = new ListNode;
	head->data = -1;
	head->next = nullptr;
	createList(head);
	//showList(head);
	showList(reverseList(head)) ;

	return 0;
}