#ifndef NODE_H
#define NODE_H
template <class T>
class Node {
	public:
		Node<T> *next;
		Node<T> *prev;
		T data;
};

#endif 
