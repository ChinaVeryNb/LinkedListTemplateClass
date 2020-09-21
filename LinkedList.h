#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
template <class T>
class List
{
public:
	List();								// 1.Constructor
	~List();							// 2.Destructor
	void AddToEnd(T data);				// 3.Create a node containing T data and add it to the front of the list
	void AddToFront(T data);			// 4.Create a node containing T data and add it to the end of the list
	void AddAtIndex(T data, int index); // 5.Create a node containing T data and add it to the list at index
	void RemoveFromFront();				// 6.Delete first item and return its contents
	void RemoveFromEnd();				// 7.Delete last item and return its contents
	void RemoveTheFirst(T data);		// 8.Find first instance of T data and remove it
	void RemoveAllOf(T data);			// 9.Find each instance of T data and remove it
	bool ElementExists(T data);			// 10.Returns a T/F if element exists in list
	Node<T> *Find(T data);				// 11.Look for data in the list, return a pointer to its node
	int IndexOf(T data);				// 12.Returns an index of the item in the list (zero-based)
	T RetrieveFront();					// 13.Returns the data contained in the first node, does not delete it
	T RetrieveEnd();					// 14.Returns the data contained in the last node, does not delete it
	T Retrieve(int index);				// 15.Returns the data contained in node # index, does not delete it
	void PrintList();					// 16.Loop through each node and print the contents of the Node
	void Empty();						// 17.Empty out the list, delete everything
	int Length();						// 18.How many elements are in the list

private:
	Node<T> *head;
	Node<T> *tail;
	int length;
};

//1 Constructor
template <typename T>
List<T>::List() 
{
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
	length = 0;
}

//2 Destructor
template <typename T>
List<T>::~List()
{
	if (length == 0)
	{
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while (head->next != nullptr) 
	{
		Node<T> *temp = head;
		head = head->next;
		delete temp; 
		temp = nullptr;
	}
	delete head;
	head = nullptr;
}

//3 create a node containing T data and add it to the front of the list
template <typename T>
void List<T>::AddToFront(T data)
{
	head->prev = new Node<T>;
	Node<T> *firstDataNode = head;
	head = firstDataNode->prev;
	head->next = firstDataNode;
	head->prev = nullptr;
	firstDataNode->data = data;
	length++;
}

//4 create a node containing T data and add it to the end of the list
template <typename T>
void List<T>::AddToEnd(T data)
{
	tail->next = new Node<T>;
	Node<T> *lastDataNode = tail;
	tail = lastDataNode->next;
	tail->prev = lastDataNode;
	tail->next = nullptr;
	lastDataNode->data = data;
	length++;
}

//5 create a node containing T data and add it to the list at index
template <typename T>
void List<T>::AddAtIndex(T data, int index)
{
	if (index > length)
	{
		std::cout << "index is bigger than length" << std::endl;
		return;
	}
	int i = 0;
	Node<T> *p;
	p = head;
	while (p->next != tail && i++ != index)
	{
		p = p->next;
	}
	Node<T> *thisDataNode = new Node<T>;
	p->next->prev = thisDataNode;
	thisDataNode->next = p->next;
	thisDataNode->prev = p;
	p->next = thisDataNode;
	thisDataNode->data = data;
	length++;
	return;
}

//6 Delete first item
template <typename T>
void List<T>::RemoveFromFront()
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return;
	}
	head->next->next->prev = head;
	head->next = head->next->next;
	length--;
	return;
}

//7 Delete last item
template <typename T>
void List<T>::RemoveFromEnd()
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return;
	}
	tail->prev->prev->next = tail;
	tail->prev = tail->prev->prev;
	length--;
	return;
}

//8 find first instance of T data and remove it
template <typename T>
void List<T>::RemoveTheFirst(T data)
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return;
	}
	Node<T> *p = head;
	while (p->next != tail)
	{
		p = p->next;
		if (p->data == data)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			length--;
			return;
		}
	}
}

//9 find each instance of T data and remove it
template <typename T>
void List<T>::RemoveAllOf(T data)
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return;
	}
	Node<T> *p = head;
	while (p->next != tail)
	{
		p = p->next;
		if (p->data == data)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			length--;
		}
	}
	return;
}

//10 Returns a T/F if element exists in list
template <typename T>
bool List<T>::ElementExists(T data)
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return false;
	}
	Node<T> *p = head;
	bool flag = false;
	while (p->next != tail)
	{
		p = p->next;
		if (p->data == data)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		return true;
	}
	else
	{
		return false;
	}
};

//11 Look for data in the list, return a pointer to its node
template <typename T>
Node<T> *List<T>::Find(T data)
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return nullptr;
	}
	Node<T> *p = head;
	bool flag = false;
	while (p->next != tail)
	{
		p = p->next;
		if (p->data == data)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		return p;
	}
	else
	{
		return nullptr;
	}
}

//12 returns an index of the item in the list (zero-based)
template <typename T>
int List<T>::IndexOf(T data)
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return -1;
	}
	int i = 0;
	Node<T> *p = head;
	bool flag = false;
	while (p->next != tail)
	{
		p = p->next;
		if (p->data == data)
		{
			flag = true;
			break;
		}
		i++;
	}
	if (flag)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

//13 returns the data contained in the first node, does not delete it
template <typename T>
T List<T>::RetrieveFront()
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return T(NULL);
	}
	return head->next->data;
}

//14 returns the data contained in the last node, does not delete it
template <typename T>
T List<T>::RetrieveEnd()
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return T(NULL);
	}
	return tail->prev->data;
}

//15 returns the data contained in node #index, does not delete it
template <typename T>
T List<T>::Retrieve(int index)
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return T(NULL);
	}
	if (index >= length)
	{
		std::cout << "index is bigger than length" << std::endl;
		return T(NULL);
	}
	int i = 0;
	Node<T> *p;
	if (index < length / 2)
	{
		p = head->next;
		while (p->next != tail && i++ != index)
		{
			p = p->next;
		}
	}
	else
	{
		p = tail->prev;
		while (p->prev != head && i++ != length - 1 - index)
		{
			p = p->prev;
		}
	}
	return p->data;
}

//16 Loop through each node and print the contents of the Node
template <typename T>
void List<T>::PrintList()
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node<T> *p = head;
	while (p->next != tail)
	{
		p = p->next;
		std::cout << p->data << " ";
	}
	std::cout << std::endl;
}

//17 Empty out the list, delete everything
template <typename T>
void List<T>::Empty()
{
	if (length == 0)
	{
		return;
	}
	Node<T> *p = head->next;
	while (p->next != tail)
	{
		Node<T> *temp = p;
		p = p->next;
		delete temp;
		temp = nullptr;
	}
	head->next = tail;
	tail->prev = head;
	length = 0;
}

//18 How many elements are in the list
template <typename T>
int List<T>::Length()
{
	return length;
}

#endif
