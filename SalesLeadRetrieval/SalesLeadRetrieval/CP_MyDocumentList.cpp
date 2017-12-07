#include"CP_MyDocumentList.h"

myDocumentList::myDocumentList()
{
	head = new myDocumentNode;
	head->ID = 0;
	head->number = 0;
	head->content = "";
	head->title = "";
	head->website = "";
	head->word_str = "";
	head->next = NULL;
	end = head;
	length = 0;
}

myDocumentList::~myDocumentList()
{
	myDocumentNode *tempNode1 = this->head;
	myDocumentNode *tempNode2 = this->head;
	while (tempNode1->next)
	{
		tempNode2 = tempNode1->next;
		delete tempNode1;
		tempNode1 = tempNode2;
	}
	delete tempNode1;
	tempNode1 = NULL;
	tempNode2 = NULL;
	head = NULL;
}

void myDocumentList::addNode(myDocumentNode *doc)
{
	length++;
	end->next = doc;
	end = doc;
	end->next = NULL;
}

void myDocumentList::removeNode(int ID)
{
	myDocumentNode *tempNode1 = head;
	while (tempNode1->next != NULL&&tempNode1->next->ID != ID)
		tempNode1 = tempNode1->next;
	if (tempNode1->next == NULL)return;
	if (tempNode1->next == end)
	{
		myDocumentNode *tempNode2 = tempNode1->next;
		end = tempNode1;
		delete tempNode2;
		tempNode1->next = NULL;
		length--;
	}
	else
	{
		myDocumentNode *tempNode2 = tempNode1->next;
		tempNode1->next = tempNode1->next->next;
		delete tempNode2;
		length--;
	}
}

myDocumentNode* myDocumentList::searchNode(int ID)
{
	myDocumentNode *node = head;
	while (node != NULL&&node->ID != ID)
		node = node->next;
	if (node == NULL) 
		return 0;
	else
		return node;
}

void myDocumentList::editNode(int ID, myString word_str, myString title, myString content, myString website, int number=0)
{
	myDocumentNode *node = searchNode(ID);
	if (node == NULL)
		return;//该结点不存在
	else//进行修改
	{
		if (word_str.length != 0)
			node->word_str = word_str;
		if (title.length != 0)
			node->title = title;
		if (content.length != 0)
			node->content = content;
		if (website.length != 0)
			node->website = website;
		if (number != 0)
			node->number = number;
	}
	return;
}