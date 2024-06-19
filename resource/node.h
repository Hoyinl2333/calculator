/*node.h*/

#pragma once

class Node
{
protected:
	Node* foreNode;
	char value;
	Node* aftNode;
public:

	Node();//���캯��������һ���ս��
	Node(const  char& val);//���캯��������һ��char����ֵ������С���㣩���洢�����


	Node* getForeNode()const;//����ǰ���ĵ�ַ
	const  char& getValue()const;//���ص�ǰ����char����ֵ
	Node* getAftNode()const;//���غ���ĵ�ַ

	void setForeNode(Node* foreObj);//����ǰ��㣬���뱻ָ���Ľ���ָ��
	void setValue(const  char& val);//���õ�ǰ����char����ֵ���������õ�ֵ
	void setAftNode(Node* aftObj);//���غ��㣬���뱻ָ���Ľ���ָ��

	static void associateNodes(Node* fore_node, Node* after_node);//Node�ྲ̬�����������������ָ�룬����ָ���������

	friend class LinkList;
	friend class Number;
};

