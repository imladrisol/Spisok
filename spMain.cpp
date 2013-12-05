#include <iostream>
#include "spisok.h"

int main()
{
	List newL;

	newL.addToEndList(2);
	newL.addToEndList(5);
	newL.addToEndList(10);
	newL.addToEndList(15);
	newL.printList();


	/*Node* findResult = newL.find(5);
	if (findResult)
	{
		 std::cout<< findResult->d;
	}*/

	newL.addToList(11, 100);
	newL.addToList(100, 200);
	newL.addToList(12, 300);


	newL.printList();

	newL.delFromList(200);
	newL.printList();
}