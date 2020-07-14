# LinkedListTemplateClass
c++实现的链表模板类：
18种函数：

1构造函数
2析构函数
//链表前添加一个data
3 AddToFront(T data) – create a node containing T data and add it to the front of the list 
//链表后添加一个data
4 AddToEnd(T data) – create a node containing T data and add it to the end of the list 
//链表指定位置添加一个data
5 AddAtIndex(T data, int index) – create a node containing T data and add it to the list at index.  The new node containing the data will be the #index node in the list. Return boolean for success or failure (optional: you could also return an integer with failure codes since this method can fail multiple ways) 
//移除第一个结点
6 RemoveFromFront() – Delete first item and return its contents 
//移除最后一个结点
7 RemoveFromEnd() – Delete last item and return its contents 
//移除找到该元素的第一个结点
8 RemoveTheFirst(T data) – find first instance of T data and remove it 
//移除找到该元素的所有结点
9 RemoveAllOf(T data) – find each instance of T data and remove it 
//判断元素是否存在
10 ElementExists(T data) – Returns a T/F if element exists in list 
//返回元素所在结点的指针
11 Find(T data) – Look for data in the list, return a pointer to its node 
//返回元素的序列号
12 IndexOf(T data) – returns an index of the item in the list (zero-based) 
//返回第一个结点中的元素
13 RetrieveFront – returns the data contained in the first node, does not delete it 
//返回最后一个结点中的元素
14 RetrieveEnd – returns the data contained in the last node, does not delete it 
//返回第n个结点中的元素
15 Retrieve(int index) – returns the data contained in node # index, does not delete it, returns null if index is out of bounds or data does not exist 
//打印链表
16 PrintList – Loop through each node and print the contents of the Node 
//清空链表
17 Empty – Empty out the list, delete everything 
//返回长度
18 Length – How many elements are in the list
