#include <iostream>
#include "spisok.h"

// must be, because -d- won't initialize
Node::Node()
{
	d = 0;
	prev = NULL;
	next = NULL;
}
//-----------------------------
List::List()
{
	pBeg = NULL;
	pEnd = NULL;
	
}
//-----------------------------
List::~List()
{
	if(pBeg)
	{
		while(pBeg!=NULL)
		{
			Node *pTemp = pBeg;
			pBeg = pBeg->next;
			std::cout << " Deleted by desctructor " << pTemp->d << std::endl;
			delete pTemp;
		}
		pBeg = NULL;
		pEnd = NULL;
	}
}
//-----------------------------

void List::printList()
{

    Node *pTemp = pBeg;		
 
	if (!pBeg)			
	{
		std::cout << "Empty List!" << std::endl;	
	}
	else				
	{
		std::cout << "List : ";		
		while(pTemp != NULL)	
		{
			std::cout << pTemp->d << " ";	
			pTemp = pTemp->next;	
		}
		std::cout << std::endl;
	}
}

//-----------------------------

Node* List::find(int d)
{
	
	Node* temp = pBeg;
	//bool fl = false;
	
	if(temp)
	{
		while(temp != NULL)
		{
			if(temp->d == d)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	else
	{
		return NULL;
	}
}
//---------------------------------
void List::addToList(int dBefore, int dIns)
{
	Node * nodeFind = find(dBefore);

	if(!pBeg)//List empty -- add new Node
	{
		Node* pv = new Node;
		pv->d = dIns;
		pBeg = pv;
		pEnd = pv;
	}
	else
	{
		if(nodeFind){ // Node found
			Node* newNode = new Node;
			newNode->next = nodeFind->next;
			newNode->prev = nodeFind;
			if(nodeFind->next!=0)
				(nodeFind->next)->prev = newNode;
			nodeFind->next = newNode;
			newNode->d = dIns;
			pEnd = newNode;
		}
		else // Node didn't find -- add at the end of the List
		{
			Node* pv = new Node;

			pv->d = dIns;
			pEnd->next = pv;
			pv->prev = pEnd;
			pEnd = pv;
		}
	}
}
//---------------------------- Check
void List::addToEndList(int d)
{
	Node* pv = new Node;
	
	if(pv){
		if(!pBeg)
		{
			pv->prev = NULL;
			pBeg = pv;
		}
		else 
		{
			pEnd->next = pv;
		}
		
		pv->d = d;
		pv->prev = pEnd;
		pv->next = NULL;
		pEnd = pv;
	}
}
//---------------------------
void List::delFromList(int d)
{
	Node* tmp = find(d);
	if(tmp)
	{
		if(tmp->prev && tmp->next) // if deleted Node in the middle of List
		{
			(tmp->prev)->next = tmp->next;
			(tmp->next)->prev = tmp->prev;
		}
		else if(tmp->prev==0 && tmp->next==0) // if deleted Node just one in the List
		{
			pBeg=NULL;
			pEnd=NULL;

		}
		else if(tmp->prev==0 && tmp->next) // if deleted Node at the begin of the List
		{
			(tmp->next)->prev = 0;
			pBeg=tmp->next;	
		}
		else if(tmp->next==0 && tmp->prev)// if deleted Node at the end of the List
		{
			(tmp->prev)->next = 0;
			pEnd=tmp->prev;	
		}
		
		std::cout << "Deleted by function " << tmp->d << std::endl;
		delete tmp;
		
	}
}
//----------------------------



