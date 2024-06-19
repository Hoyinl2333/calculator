/*linkList.h*/

#pragma once

#include<iostream>

class Node;

class LinkList
{
protected:
	Node* head;
	Node* tail;
	Node* decimalPoint;
	bool isDouble;

public:

	enum insertLocation { Head = 0, Middle, Tail };//枚举量，用于insert()函数，表示插入结点位置

	LinkList();//构造函数，创建一个空链表
	LinkList(std::string number);//构造函数，接受一个std::string表示的数，创建相应链表
	LinkList(const LinkList& other);//复制构造函数，创建一个相同的链表

	virtual ~LinkList();//析构函数，清理链表

	Node* gethead()const;//返回指向链表头结点的指针
	Node* gettail()const;//返回指向链表尾结点的指针
	Node* getDecimalPoint()const;//返回指向链表小数点的指针
	bool getIsDouble()const;//返回是否为小数的布尔值

	void sethead(Node* head_node);//设置头结点，输入被设置为头节点的结点指针
	void settail(Node* tail_node);//设置尾结点，输入被设置为尾节点的结点指针
	void setDecimalPoint(Node* decimalPoint_node);//设置小数点结点，输入被设置为小数点节点的结点的指针
	void setIsDouble(bool doubleCheck);//设置是否为小数

	void append(const char& val);//在链表尾部追加值为val的结点
	void insert(const char& val, LinkList::insertLocation location = Head, Node* point = nullptr);//在指定位置插入值为val的结点
	void createList(std::string number);//接受std::string对象为参数，创建对应的链表

	std::string toString()const;//将链表转换为std::string类对象输出

};

