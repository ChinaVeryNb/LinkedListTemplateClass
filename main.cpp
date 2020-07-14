#include<iostream>
#include"LinkedList.h"
//Instantiation of linked list template class
int main() {
	List<int> ls;
	ls.AddToEnd(11);
	ls.AddToEnd(22);
	ls.AddToEnd(33);
	ls.AddToEnd(44);
	ls.AddToEnd(44);
	ls.AddToEnd(44);
	ls.AddToEnd(55);
	ls.AddToFront(666);
	ls.AddAtIndex(77,4);
	ls.PrintList();
	std::cout << ls.Length() << std::endl;
	std::cout << ls.Retrieve(1) << std::endl;
	ls.RemoveTheFirst(44);
	ls.PrintList();
	ls.RemoveAllOf(44);
	ls.PrintList();
	ls.RemoveFromFront();
	ls.PrintList();
	ls.RemoveFromEnd();
	ls.PrintList();
	std::cout<<ls.ElementExists(3)<<std::endl;
	std::cout<<ls.Find(33)<<std::endl;
	std::cout<<ls.IndexOf(33)<<std::endl;
	std::cout<<ls.RetrieveFront()<<std::endl;
	std::cout<<ls.RetrieveEnd()<<std::endl;
	system("pause");
	return 0;
}

