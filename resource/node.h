/*node.h*/

#pragma once

class Node
{
protected:
	Node* foreNode;
	char value;
	Node* aftNode;
public:

	Node();//构造函数，创建一个空结点
	Node(const  char& val);//构造函数，接受一个char类型值（数或小数点），存储进结点


	Node* getForeNode()const;//返回前结点的地址
	const  char& getValue()const;//返回当前结点的char类型值
	Node* getAftNode()const;//返回后结点的地址

	void setForeNode(Node* foreObj);//设置前结点，输入被指定的结点的指针
	void setValue(const  char& val);//设置当前结点的char类型值，输入设置的值
	void setAftNode(Node* aftObj);//返回后结点，输入被指定的结点的指针

	static void associateNodes(Node* fore_node, Node* after_node);//Node类静态函数，接受两个结点指针，连接指向两个结点

	friend class LinkList;
	friend class Number;
};

