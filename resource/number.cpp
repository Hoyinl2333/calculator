/*number.cpp*/

#include "number.h"
#include"node.h"
#include<iostream>
#include<cmath>

const unsigned int Number::DIVISION_PRECISION = 20;//设置到除不尽保留小数点后20位

Number::Number() :LinkList(),
integerLength(0), decimalLength(0), isNegative(0)
{
}

Number::Number(std::string number) :LinkList(number), isNegative(number.at(0) == '-' ? 1 : 0)
{
	simply();
	integerLength = countIntLen();
	decimalLength = countDecLen();
}

Number::Number(int aNum) :LinkList(), isNegative(false)
{
	std::string num = std::to_string(aNum);
	createList(num);
	simply();
	integerLength = countIntLen();
	decimalLength = countDecLen();
}

Number::Number(const Number& other) :LinkList(other), isNegative(other.isNegative),
decimalLength(other.decimalLength), integerLength(other.integerLength)
{
}


int Number::getIntLen() const
{
	return integerLength;
}

int Number::getDecLen() const
{
	return decimalLength;
}

bool Number::getIsNegative() const
{
	return isNegative;
}

void Number::setIntLen(const int& int_length)
{
	integerLength = int_length;
}

void Number::setDecLen(const int& dec_length)
{
	decimalLength = dec_length;
}

void Number::setIsNegative(bool is_negetive)
{
	isNegative = is_negetive;
}

void Number::simply()
{
	//化简整数部分
	Node* current = head;
	if (current == NULL)
	{
		return;
	}
	while (current->value == '0')
	{
		if (current->aftNode == NULL)
		{
			break;
		}
		if (current->aftNode->value == '.')
		{
			break;
		}
		Node* next = current->aftNode;
		delete current;
		current = next;
		current->foreNode = NULL;
	}
	if (head != current)
	{
		head = current;
	}

	//化简小数部分
	if (!isDouble)
	{
		return;
	}
	current = tail;
	while (current->value == '0')
	{
		Node* before = current->foreNode;
		before->aftNode = NULL;
		delete current;
		current = before;
	}
	if (current->value == '.')
	{
		Node* before = current->foreNode;
		delete current;
		current = before;
		current->aftNode = NULL;

		isDouble = false;
	}
	if (tail != current)
	{
		tail = current;
	}

}

void Number::setPrecision(const int& p)
{
	if (decimalLength <= p)
	{
		if (decimalLength == 0)
		{
			append('.');
			isDouble = true;
		}
		for (int i = decimalLength; i < p; ++i)
		{
			append('0');
		}
		decimalLength = p;
		return;
	}
	else
	{
		//需要四舍五入的情况
		Node* current = decimalPoint;
		for (int i = 0; i <= p; ++i)//将current指针移动到目标精度下一位
		{
			current = current->aftNode;
		}
		if (current->value > '4')
		{
			std::string add_number = Number::to_string_with_precision(pow(10, -p), p);
			Number add(add_number);
			*this = *this + add;
		}

		//四舍五入之后赋值产生的是新的this指针
		current = decimalPoint;
		for (int i = 0; i <= p; ++i)//将current指针移动到目标精度下一位
		{
			current = current->aftNode;
		}
		tail = current->foreNode;
		tail->aftNode = NULL;
		while (current != nullptr)
		{
			current->foreNode = NULL;
			Node* next = current->aftNode;
			delete current;
			current = next;
		}
	}
}

std::string Number::toString() const
{
	std::string result;
	if (isNegative)
	{
		result.append("-");
	}
	result += LinkList::toString();
	return result;
}

std::string Number::to_string(const Number& number)
{

	return number.toString();
}

Number Number::slice(Node* start, Node* end, Number::sliceOption option)
{
	bool hasDecPoint;//根据option决定是否保留小数
	switch (option)
	{
	case Number::KeepDot:
		hasDecPoint = true;
		break;
	case Number::NotKeepDot:
		hasDecPoint = false;
		break;
	default:
		hasDecPoint = true;
		break;
	}

	//如果接收到的是空指针返回0;
	if (start == NULL || end == NULL)
	{
		return Number(0);
	}

	Node* t, * h;
	Number result;
	result.decimalPoint = NULL;
	for (h = start, t = end->aftNode; h != NULL && (h != t); h = h->aftNode)
	{
		if (h->value == '.')
		{
			if (!hasDecPoint)
			{
				continue;
			}
			result.isDouble = true;
			result.decimalPoint = result.tail;
		}
		result.append(h->value);
	}

	result.integerLength = result.countIntLen();
	result.decimalLength = result.countDecLen();
	return result;
}

int Number::countIntLen()
{
	int len = 0;
	Node* current = head;
	while (current != NULL && current->value != '.')
	{
		++len;
		current = current->aftNode;
	}
	return len;
}

int Number::countDecLen()
{
	if (!isDouble)
	{
		return 0;
	}
	int len = 0;
	Node* current = tail;
	while (current != NULL && current->value != '.')
	{
		++len;
		current = current->foreNode;
	}
	return len;
}

Number& Number::operator=(const Number& number)
{
	if (this == &number)
	{
		return *this;
	}
	this->isDouble = number.isDouble;
	this->isNegative = number.isNegative;
	this->integerLength = number.integerLength;
	this->decimalLength = number.decimalLength;

	//链表初始化
	//清理旧值
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

	//创建新值
	current = number.head;
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
	return *this;
}

bool operator>(const Number& number1, const Number& number2)
{
	Number n1 = number1;
	Number n2 = number2;
	n1.simply();
	n2.simply();

	if (n1.integerLength > n2.integerLength)//整数部分长度比较
	{
		return true;
	}
	else if (n1.integerLength < n2.integerLength)//整数部分长度比较
	{
		return false;
	}
	else//整数部分长度相同
	{
		Node* p = n1.head;
		Node* q = n2.head;
		while (p != NULL && q != NULL && p->getValue() == q->getValue())
		{
			p = p->getAftNode();
			q = q->getAftNode();
		}
		if (p != NULL)
		{
			if (q == NULL)
			{
				return true;
			}
			return p->getValue() > q->getValue() ? true : false;
		}
		else
		{
			return false;
		}
	}
}

Number operator+(const Number& number1, const Number& number2)
{

	if (number1.head == NULL || number2.head == NULL)
	{
		return Number();
	}

	//根据符号判断是否真的为加法
	if (number1.isNegative ^ number2.isNegative)
	{
		Number tem;
		if (number1.isNegative)
		{
			tem = number1;
			tem.isNegative = false;
			return number2 - tem;
		}
		else
		{
			tem = number2;
			tem.isNegative = false;
			return number1 - tem;
		}
	}

	Number result;
	result.isNegative = (number1.isNegative);
	result.isDouble = (number1.isDouble || number2.isDouble);//初始化result

	int carry = 0;

	Node* temp1, * temp2;
	if (number1.decimalLength >= number2.decimalLength)
	{
		temp1 = number1.tail; temp2 = number2.tail;
	}
	else
	{
		temp1 = number2.tail; temp2 = number1.tail;
	}//选择尾部长者为temp1

	if (number1.isDouble || number2.isDouble)//计算小数部分
	{

		for (int i = 0; i < abs(number1.decimalLength - number2.decimalLength); ++i)
		{
			result.insert(temp1->getValue(), LinkList::Head);
			temp1 = temp1->getForeNode();
		}
		while (temp1->getValue() != '.')
		{
			result.insert(char((temp1->getValue() + temp2->getValue() + carry - 96) % 10 + 48), LinkList::Head);
			carry = (temp1->getValue() + temp2->getValue() + carry - 96) / 10;
			temp1 = temp1->getForeNode();
			temp2 = temp2->getForeNode();
		}

		result.insert('.', LinkList::Head);
		result.setDecimalPoint(result.gethead());//标记小数点

		temp1 = temp1->getForeNode();
		if (temp2->getValue() == '.')
		{
			temp2 = temp2->getForeNode();
		}
	}

	//计算整数部分
	while (temp1 != NULL && temp2 != NULL)
	{
		result.insert(char((temp1->getValue() + temp2->getValue() + carry - 96) % 10 + 48), LinkList::Head);
		carry = (temp1->getValue() + temp2->getValue() + carry - 96) / 10;
		temp1 = temp1->getForeNode();
		temp2 = temp2->getForeNode();
	}
	if (temp1 == NULL)
	{
		temp1 = temp2;
		temp2 = NULL;
	}
	while (temp1 != NULL)
	{
		result.insert(char((temp1->getValue() + carry - 48) % 10 + 48), LinkList::Head);
		carry = (temp1->getValue() + carry - 48) / 10;
		temp1 = temp1->getForeNode();
	}
	if (temp1 == NULL && carry)
	{
		result.insert('1', LinkList::Head);
	}
	//后处理
	result.simply();
	result.decimalLength = result.countDecLen();
	result.integerLength = result.countIntLen();
	return result;
}

Number operator-(const Number& number1, const Number& number2)
{
	if (number1.head == NULL || number2.head == NULL)
	{
		return Number();
	}
	//调整真实情况
	if (number1.isNegative ^ number2.isNegative)
	{
		Number tem;
		if (number1.isNegative)
		{
			tem = number2;
			tem.isNegative = true;
			return tem + number1;
		}
		else
		{
			tem = number2;
			tem.isNegative = false;
			return number1 + tem;
		}
	}

	Number result;
	result.isNegative = (number2 > number1 ? !number2.isNegative : number2.isNegative);
	result.isDouble = (number1.isDouble || number2.isDouble);//初始化result

	Node* temp1;
	Node* temp2;

	//temp1指向绝对值较大者，temp2指向绝对值较小者,两者相等返回0
	if (number1 > number2)
	{
		temp1 = number1.tail;
		temp2 = number2.tail;
	}
	else if (number2 > number1)
	{
		temp1 = number2.tail;
		temp2 = number1.tail;
	}
	else
	{
		result.append('0');
		result.isDouble = false;
		result.isNegative = false;
		return result;
	}

	//计算减法,从小数部分开始

	int borrow = 0;//借位


	//计算小数部分
	if (number1.decimalLength || number2.decimalLength)
	{
		bool isDecLongger = true;//较大者的小数部分更长吗？
		if (temp1 == number1.tail)
		{
			isDecLongger = (number1.decimalLength >= number2.decimalLength ? 1 : 0);
		}
		else
		{
			isDecLongger = (number2.decimalLength >= number1.decimalLength ? 1 : 0);;
		}
		for (int i = 0; i < abs(number1.decimalLength - number2.decimalLength); i++)
		{
			result.insert(isDecLongger ? char(temp1->getValue() - borrow) : char(106 - temp2->getValue() - borrow), LinkList::Head);
			isDecLongger ? (temp1 = temp1->getForeNode()) : (temp2->getForeNode());
			borrow = isDecLongger ? 0 : 1;
		}
		while (temp1->getValue() != '.' && temp2->getValue() != '.')
		{
			result.insert(temp1->getValue() >= temp2->getValue() + borrow ? char(temp1->getValue() - temp2->getValue() - borrow + 48) : char(temp1->getValue() - temp2->getValue() - borrow + 58),
				LinkList::Head);
			borrow = temp1->getValue() >= temp2->getValue() + borrow ? 0 : 1;
			temp1 = temp1->getForeNode();
			temp2 = temp2->getForeNode();
		}

		result.insert('.', LinkList::Head);
		result.decimalPoint = result.head;

		if (temp1->getValue() == '.')
		{
			temp1 = temp1->getForeNode();
		}
		if (temp2->getValue() == '.')
		{
			temp2 = temp2->getForeNode();
		}
	}

	//计算整数部分
	while (temp1 != NULL && temp2 != NULL)
	{
		result.insert(temp1->getValue() >= temp2->getValue() + borrow ? char(temp1->getValue() - temp2->getValue() - borrow + 48) : char(temp1->getValue() - temp2->getValue() - borrow + 58),
			LinkList::Head);
		borrow = temp1->getValue() >= (temp2->getValue() + borrow) ? 0 : 1;
		temp1 = temp1->getForeNode();
		temp2 = temp2->getForeNode();
	}
	while (temp1 != NULL)
	{
		char number = temp1->getValue() - borrow > 47 ? char(temp1->getValue() - borrow) : '9';
		borrow = temp1->getValue() - borrow > 47 ? 0 : 1;
		if (number > 47 && number < 58)
		{
			result.insert(number, LinkList::Head);
		}
		else
		{
			break;
		}
		temp1 = temp1->getForeNode();
	}
	//后处理
	result.simply();
	result.decimalLength = result.countDecLen();
	result.integerLength = result.countIntLen();

	return result;
}

Number operator*(const Number& number, Node* node)
{

	int num = node->getValue() - 48;
	char val = NULL;
	int carry = 0;

	Node* p = number.tail;
	Number result;

	//遍历链表
	while (p != NULL)
	{
		if (p->getValue() != '.')
		{
			val = char((num * (p->getValue() - 48) + carry) % 10 + 48);
			carry = (num * (p->getValue() - 48) + carry) / 10;
			result.insert(val, LinkList::Head);
		}
		p = p->getForeNode();
	}
	//最终是否还要进位
	if (carry)
	{
		result.insert(char(carry + 48), LinkList::Head);
	}
	//后处理
	result.simply();
	result.decimalLength = result.countDecLen();
	result.integerLength = result.countIntLen();
	return result;
}

Number operator*(const Number& number1, const Number& number2)
{
	if (number1.head == NULL || number2.head == NULL)
	{
		return Number();
	}
	Number result, temp;
	result.isNegative = (number1.isNegative ^ number2.isNegative);
	result.isDouble = (number1.isDouble || number2.isDouble);
	Node* t = number2.tail;


	for (int i = 0; t != nullptr; t = t->getForeNode())//实现不考虑小数点情况下的简单链表相乘
	{
		if (t->getValue() != '.')
		{
			temp = number1 * t;//结点乘链表
			for (int j = 0; j < i; j++)
			{
				temp.append('0');
				++temp.integerLength;
			}
			result = result + temp;
			i++;
		}
	}

	//确定小数点
	t = result.tail;
	int k = 0;
	for (; k < number1.decimalLength + number2.decimalLength; k++)
	{
		t = t->getForeNode();
		if (t == NULL)
		{
			result.insert('0', LinkList::Head);
			t = result.head;
		}
	}
	if (k)
	{
		result.insert('.', LinkList::Middle, t);
		result.decimalPoint = t->getAftNode();
		result.isDouble = true;
	}
	//后处理
	result.simply();
	result.decimalLength = result.countDecLen();
	result.integerLength = result.countIntLen();

	return result;
}

Number operator/(const Number& number1, const Number& number2)
{
	if (number1.head == NULL || number2.head == NULL)
	{
		return Number();
	}
	//预处理部分：
	//除数是否零
	/*Number zero_judege(std::to_string(0.000001));
	if (zero_judege > number2)
	{
		throw std::runtime_error("divide zero error!");
	}*/
	Number result;
	Number isdividend = number1;
	Number dividend = number2;
	Number* tempIsdividend = NULL;

	//调整被除数和除数的小数位数（除数是小数的情况）
	if (dividend.decimalLength)
	{
		//调整被除数
		Node* dividend_p = dividend.decimalPoint;
		Node::associateNodes(dividend_p->getForeNode(), dividend_p->getAftNode());
		delete dividend_p;
		dividend.decimalPoint = NULL;
		dividend.isDouble = false;//这里不能着急调整除数的位数，调整被除数时会使用


		//调整被除数
		if (isdividend.decimalLength)//被除数是小数
		{
			Node* isdividend_p = isdividend.decimalPoint;
			Node::associateNodes(isdividend_p->getForeNode(), isdividend_p->getAftNode());
			delete isdividend_p;
			isdividend.decimalPoint = NULL;
			isdividend.isDouble = false;
		}
		int n = isdividend.decimalLength - dividend.decimalLength;//被除数小数位数和除数小数位数的差
		if (n <= 0)//被除数小数位数不多于除数
		{
			for (int i = 0; i < abs(n); i++)
			{
				isdividend.append('0');
			}
			//isdividend.decimalLength = 0;
			//isdividend.integerLength += dividend.decimalLength + abs(n);
		}
		else
		{
			Node* t = isdividend.tail;
			for (int i = 0; t != NULL && i < n; i++)
			{
				t = t->getForeNode();
			}
			isdividend.insert('.', LinkList::Middle, t);
			//isdividend.integerLength += dividend.decimalLength;
			//isdividend.decimalLength -= dividend.decimalLength;
			isdividend.isDouble = true;
		}

		//修正整数开头为0情况
		dividend.simply();
		isdividend.simply();

		//最后调整被除数和除数的整数部分长度和小数部分的长度
		dividend.integerLength = dividend.countIntLen();
		dividend.decimalLength = 0;
		isdividend.integerLength = isdividend.countIntLen();
		isdividend.decimalLength = isdividend.countDecLen();
	}
	//强制变成浮点数，例"123"转为"123.0"，后面有用
	if (!isdividend.isDouble)
	{
		isdividend.append('.');
		isdividend.append('0');
		isdividend.isDouble = true;
		++isdividend.decimalLength;
	}


	//除法实现部分：

	Node* temp = NULL;
	int oldLen;
	bool isOnlyInherited;
	while (isdividend.head)
	{
		oldLen = 0;//继承上一次除法未除尽的长度
		isOnlyInherited = false;//是否仅继承上一次未除尽的数作为下一次的被除数

		//继承上一次未除尽的数
		if (tempIsdividend != NULL && *tempIsdividend > 0)
		{
			oldLen = tempIsdividend->integerLength;//按理来说这时候isdividend的小数部分不存在，长度为0
			isOnlyInherited = temp->getAftNode() == NULL ? true : false;

			//将上次未除尽的数连接
			isdividend = isdividend.slice(temp->getAftNode(), isdividend.tail, Number::KeepDot);//如果temp->getAftNode()==NULL,则isdividend为一个‘0’
			Node::associateNodes(tempIsdividend->tail, isdividend.head);
			isdividend.head = tempIsdividend->head;
			isdividend.integerLength += tempIsdividend->integerLength;
			tempIsdividend = NULL;
			//delete tempIsdividend;
		}
		else
		{
			if (temp)
			{
				if (temp->getAftNode())
				{
					isdividend = isdividend.slice(temp->getAftNode(), isdividend.tail, Number::KeepDot);
				}
				else
				{
					break;//彻底整除
				}
			}
		}
		temp = isdividend.head;

		//调整起始位置
		while (temp && (temp->getValue() == '0' || temp->getValue() == '.'))
		{
			result.append(temp->getValue());
			if (temp->getValue() == '.')
			{
				result.isDouble = true;
				result.decimalPoint = result.tail;
			}
			temp = temp->getAftNode();

		}
		if (temp == NULL)//此时是完全整除情况
		{
			break;
		}

		//寻找位置
		int i = 1;
		Node* temph = temp;
		if (isOnlyInherited)
		{
			temp = isdividend.tail;
			i = oldLen + 1;
		}
		for (; i <= dividend.integerLength; i++)
		{
			if (i > oldLen && i < dividend.integerLength)
			{
				result.append('0');
			}
			else if (i == dividend.integerLength)
			{
				if (dividend > isdividend.slice(temph, temp, Number::NotKeepDot))
				{
					if (i > oldLen)
					{
						result.append('0');
					}
				}
				else
				{
					break;
				}
			}
			temp = temp->getAftNode();

			if (temp && temp->getValue() == '.')
			{
				result.append('.');
				result.isDouble = true;
				result.decimalPoint = result.tail;
				temp = temp->getAftNode();
			}
			if (temp == NULL)
			{
				isdividend.append('0');
				temp = isdividend.tail;
			}
		}


		tempIsdividend = new Number(isdividend.slice(temph, temp, Number::NotKeepDot));

		//预估、计算实际值
		int properVal = 0;
		if (i == dividend.integerLength)
		{
			properVal = (temph->getValue() - 48) / (dividend.head->getValue() - 48 + 1);
		}
		else
		{
			properVal = ((temph->getValue() - 48) * 10 + (temph->getAftNode()->getValue() - 48)) / (dividend.head->getValue() - 48 + 1);
		}
		//应该不会有properVal<0的情况出现，仅做检查
		if (properVal < 0)
		{
			properVal = 0;
		}
		//计算
		*tempIsdividend = *tempIsdividend - (dividend * properVal);
		int j = properVal;
		for (; j < 10; ++j)
		{
			if (dividend > *tempIsdividend)
			{
				break;
			}
			*tempIsdividend = *tempIsdividend - dividend;
		}

		//存储商
		result.append(char(j + 48));

		//是否有小数点
		if (temp != NULL && temp->getAftNode() && temp->getAftNode()->getValue() == '.')
		{
			result.append('.');
			result.isDouble = true;
			result.decimalPoint = result.tail;
			temp = temp->getAftNode();
		}

		//判断小数位数是否达到精度值,如果达到则四舍五入
		if ((result.decimalLength = result.countDecLen()) > Number::DIVISION_PRECISION)
		{
			result.setPrecision(Number::DIVISION_PRECISION);
			break;
		}
	}

	//后处理：

	result.simply();
	result.integerLength = result.countIntLen();
	result.decimalLength = result.countDecLen();
	return result;

}

