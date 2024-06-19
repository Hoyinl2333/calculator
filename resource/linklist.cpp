/*linkList.cpp*/


#include "linklist.h"
#include<iostream>
#include"node.h"
#include<string>


LinkList::LinkList() :head(nullptr), tail(nullptr),
    decimalPoint(nullptr), isDouble(false)
{
}

LinkList::LinkList(std::string number):head(nullptr), tail(nullptr),
    decimalPoint(nullptr), isDouble(false)
{
    std::string str = number;
    if (number.at(0) == '-')
    {
        str.erase(str.begin());
    }
    createList(str);
}

LinkList::LinkList(const LinkList& other):head(nullptr), tail(nullptr),
    decimalPoint(nullptr), isDouble(other.isDouble)
{
    Node* current = other.head;
    while (current != nullptr)
    {
        // 创建新节点并复制数据
        Node* newNode = new Node(current->value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node::associateNodes(tail, newNode);
        }
        if (current->value == '.')
        {
            decimalPoint = newNode;
        }
        tail = newNode;
        current = current->aftNode;
    }
}

LinkList::~LinkList()
{
    Node* current = head;
    while (current != nullptr)
    {
        current->foreNode = NULL;
        Node* next = current->aftNode;
        delete current;
        current = next;

    }
    tail = NULL;
    head = NULL;
}

Node* LinkList::gethead() const
{
    return head;
}

Node* LinkList::gettail() const
{
    return tail;
}

Node* LinkList::getDecimalPoint() const
{
    return decimalPoint;
}

bool LinkList::getIsDouble() const
{
    return isDouble;
}

void LinkList::sethead(Node* head_node)
{
    head = head_node;
}

void LinkList::settail(Node* tail_node)
{
    tail = tail_node;
}

void LinkList::setDecimalPoint(Node* decimalPoint_node)
{
    decimalPoint = decimalPoint_node;
}

void LinkList::setIsDouble(bool doubleCheck)
{
    isDouble = doubleCheck;
}


void LinkList::append(const char& val)
{
    Node* newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    Node::associateNodes(tail, newNode);
    tail = newNode;
}

void LinkList::insert(const char& val, LinkList::insertLocation location, Node* point)
{
    Node* newNode = new Node(val);
    switch (location)
    {
    case Head:
        //在头部插入一个结点
        if (head == NULL)
        {
            tail = newNode;
        }
        else
        {
            Node::associateNodes(newNode, head);
        }
        head = newNode;
        break;
    case Tail:
        //在尾部插入一个结点
        if (tail == NULL)
        {
            head = newNode;
        }
        else
        {
            Node::associateNodes(tail, newNode);
        }
        tail = newNode;
        break;
    case Middle:
        //向指定位置后插入一个结点
        if (point == NULL || point->aftNode == NULL)
        {
            delete newNode;
            return;
        }
        Node* tem = point->aftNode;
        Node::associateNodes(point, newNode);
        Node::associateNodes(newNode, tem);
        break;
    }
}

void LinkList::createList(std::string number)
{
    for (auto it = number.begin(); it != number.end(); ++it)
    {
        if (*it == ',')
        {
            ++it;
        }

        Node* newNode = new Node(*it);
        if (head != nullptr)
        {
            Node::associateNodes(tail, newNode);
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
        if (*it == '.')
        {
            isDouble = true;
            decimalPoint = newNode;
        }
    }
}

std::string LinkList::toString()const
{
    std::string result;
    Node* current = tail;
    int i = 0;
    bool isDoublePart = isDouble ? true : false;

    while (current != NULL)
    {
        ++i;

        if (current->value == '.')
        {
            i = 0;
            isDoublePart = false;
            result = "." + result;
            current = current->foreNode;
            continue;
        }
        result = std::to_string(current->value - 48) + result;
        current = current->foreNode;
        if (!isDoublePart && i % 3 == 0 && current != NULL)
        {
            result = "," + result;
        }
    }
    return result;
}



