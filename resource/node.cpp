/*node.cpp*/


#include "Node.h"

Node::Node() :foreNode(nullptr), value('\0'), aftNode(nullptr)
{
}

Node::Node(const char& val) :foreNode(nullptr), value(val), aftNode(nullptr)
{
}

Node* Node::getForeNode() const
{
	return foreNode;
}

const char& Node::getValue() const
{
	return value;
}

Node* Node::getAftNode() const
{
	return aftNode;
}

void Node::setForeNode(Node* foreObj)
{
	foreNode = foreObj;
}

void Node::setValue(const char& val)
{
	value = val;
}

void Node::setAftNode(Node* aftObj)
{
	aftNode = aftObj;
}

void Node::associateNodes(Node* fore_node, Node* after_node)
{
	fore_node->aftNode = after_node;
	after_node->foreNode = fore_node;
}


