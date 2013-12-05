#define __SPISOK_H__
#ifdef __SPISOK_H__

class Node
{
public:
	int d;
	Node* prev;
	Node* next;	

	Node();
};
class List: Node
{
public:
	Node* pBeg;
	Node* pEnd;
	
	List();
	~List();

	void addToList(int d, int d1);
	void delFromList(int d);
	Node * find(int d);
	void addToEndList(int d);
	void printList();
	
};
#endif //__SPISOK_H__