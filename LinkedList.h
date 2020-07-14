#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
template <class T>
class List {
	public:
		List();//1 Constructor
		~List();//2 Destructor
		void AddToEnd(T data);//3 create a node containing T data and add it to the front of the list 
		void AddToFront(T data);//4 create a node containing T data and add it to the end of the list 
		void AddAtIndex(T data, int index);//5 create a node containing T data and add it to the list at index
		void RemoveFromFront();//6 Delete first item and return its contents 
		void RemoveFromEnd();//7 Delete last item and return its contents 
		void RemoveTheFirst(T data);//8 find first instance of T data and remove it
		void RemoveAllOf(T data);//9 find each instance of T data and remove it 
		bool ElementExists(T data);//10 Returns a T/F if element exists in list
		Node<T> *Find(T data);//11 Look for data in the list, return a pointer to its node 
		int IndexOf(T data);//12 returns an index of the item in the list (zero-based) 
		T RetrieveFront();//13 returns the data contained in the first node, does not delete it 
		T RetrieveEnd();//14 returns the data contained in the last node, does not delete it 
		T Retrieve(int index);//15 returns the data contained in node # index, does not delete it
		void PrintList();//16 Loop through each node and print the contents of the Node 
		void Empty();//17 Empty out the list, delete everything 
		int Length();//18 How many elements are in the list
	private:
		Node<T> *head;
		Node<T> *tail;
		int length;
};

//1 Constructor
template <typename T>
List<T>::List() {//初始化两个节点 头和尾
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
List<T>::~List() {
	if(length == 0) {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while(head->next != nullptr) {
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
}

//3 create a node containing T data and add it to the front of the list 
template <typename T>
void List<T>::AddToFront(T data) {
	Node<T>* temp = this->head;
	head->data = data;
	head->prev = new Node<T>;
	Node<T> *p = head;
	head = head->prev;
	head->next = p;
	head->prev = nullptr;
	length++;
}

//4 create a node containing T data and add it to the end of the list 
template <typename T>
void List<T>::AddToEnd(T data) {
	Node<T>* temp = this->tail;
	tail->data = data;
	tail->next = new Node<T>;
	Node<T> *p = tail;
	tail = tail->next;
	tail->prev = p;
	tail->next = nullptr;
	length++;
}

//5 create a node containing T data and add it to the list at index
template <typename T>
void List<T>::AddAtIndex(T data, int index) {
	if(index >= length) {
		std::cout<<"index is bigger than length"<<std::endl;
		return ;
	}
	int x = 0;
	Node<T> *p;
	p = head->next;
	while (p->next != nullptr && ++x != index) {
		p=p->next;
	}
	Node<T>* temp = p->next;
	p->next = new Node<T>;
	p->next->data = data;
	p->next->prev = p;
	p->next->next = temp;
	temp->prev = p->next;
	length++;
	return ;
}

//6 Delete first item and return its contents 
template <typename T>
void List<T>::RemoveFromFront() {
	if(length == 0) {
		std::cout << "List is empty";
		return ;
	}
	this->head->next->next->prev = this->head;
	this->head->next = this->head->next->next;
	length--;
	return ;

}

//7 Delete last item and return its contents 
template <typename T>
void List<T>::RemoveFromEnd() {
	if(length == 0) {
		std::cout << "List is empty";
		return ;
	}
	this->tail->prev->prev->next = this->tail;
	this->tail->prev = this->tail->prev->prev;
	length--;
	return ;

}

//8 find first instance of T data and remove it
template <typename T>
void List<T>::RemoveTheFirst(T data) {
	if(length == 0) {
		std::cout << "List is empty";
		return ;
	}
	Node<T> *p = head;
	while(p->next!=nullptr) {
		p = p->next;
		if(p->data == data) {
			Node<T> *temp = p->prev;
			temp->next = p->next;
			p->next->prev = temp;
			delete p;
			length--;
			return ;
		}
	}
}

//9 find each instance of T data and remove it 
template <typename T>
void List<T>::RemoveAllOf(T data) {
	if(length == 0) {
		std::cout << "List is empty";
		return ;
	}
	Node<T> *p = head;
	while(p->next!=nullptr) {
		p = p->next;
		if(p->data == data) {
			Node<T> *temp = p->prev;
			temp->next = p->next;
			p->next->prev = temp;
			length--;
		}
	}
	return ;
}

//10 Returns a T/F if element exists in list
template <typename T>
bool List<T>::ElementExists(T data) {
	if(length == 0) {
		std::cout << "List is empty" << std::endl;
		return false;
	}
	Node<T> *p = head->next;
	bool flag = false;
	while (p != tail) {
		if(p->data == data){
			flag = true;
		}
		p = p->next;
	}
	if(flag){
		return true;
	} else {
		return false;
	}
}
;

//11 Look for data in the list, return a pointer to its node
template <typename T>
Node<T>* List<T>::Find(T data) {
	if(length == 0) {
		std::cout << "List is empty" << std::endl;
		return nullptr;
	}
	Node<T> *p = head->next;
	while (p != tail) {
		if(p->data == data){
			return p;
		}
		p = p->next;
	}
	return nullptr;
}

//12 returns an index of the item in the list (zero-based) 
template <typename T>
int List<T>::IndexOf(T data) {
	if(length == 0) {
		std::cout << "List is empty" << std::endl;
		return -1;
	}
	int x = 0;
	Node<T> *p = head->next;
	while (p != tail) {
		if(p->data == data){
			return x;
		}
		x++;
		p = p->next;
	}
	return -1;
}

//13 returns the data contained in the first node, does not delete it 
template <typename T>
T List<T>::RetrieveFront() {
	return head->next->data;
}

//14 returns the data contained in the last node, does not delete it 
template <typename T>
T List<T>::RetrieveEnd() {
	return tail->prev->data;
}

//15 returns the data contained in node # index, does not delete it
template <typename T>
T List<T>::Retrieve(int index) {
	if(length == 0) {
		return NULL;
	}
	if(index >= length) {
		return NULL;
	}
	int x = 0;
	T data;
	Node<T> *p;
	if(index < length/2) {
		p = head->next;
		while (p->next != nullptr && x++ != index) {
			p=p->next;
		}
	} else {
		p = tail->prev;
		while(p->prev != nullptr && x++ != index) {
			p = p->prev;
		}
	}
	return p->data;
}

//16 Loop through each node and print the contents of the Node 
template <typename T>
void List<T>::PrintList() {
	if(length == 0) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node<T> *p = head->next;
	while (p != tail) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

//17 Empty out the list, delete everything 
template <typename T>
void List<T>:: Empty() {
	if(length == 0) {
		return ;
	}
	Node<T> *p = head->next;
	while(p != tail) {
		Node<T>* temp = p;
		p = p->next;
		delete temp;
	}
	head->next = tail;
	tail->prev = head;
	length = 0;
}

//18 How many elements are in the list
template <typename T>
int List<T>::Length() {
	return length;
}

#endif
