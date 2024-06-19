/*number.h*/


#pragma once
#include "linklist.h"
#include<string>
#include<sstream>
#include<iomanip>

class Number :
	public LinkList
{
private:

	int integerLength;
	int decimalLength;
	bool isNegative;

	template<typename T>
	static std::string to_string_with_precision(const T val, const int precision = -1);//模板函数，将各种类型数转化为string类型，带精度

public:

	enum sliceOption { KeepDot, NotKeepDot };//枚举量，便于管理slice()函数，前者保留小数点，后者不保留
	static const unsigned int DIVISION_PRECISION;//除法的精度，默认设置为6;

	Number();//构造函数，创建一个空的“数”
	Number(std::string number);//构造函数，根据传入的std::string类型数转换为一个链表
	Number(int aNum);//构造函数，根据传入的int类型数转换为一个链表
	Number(const Number& number);//复制构造函数



	int getIntLen()const;//返回数的整数部分长度
	int getDecLen()const;//返回数的小数部分长度
	bool getIsNegative()const;//返回是否为负数的布尔值

	void setIntLen(const int& int_length);//设置数的整数部分长度
	void setDecLen(const int& dec_length);//设置数的小数部分的长度
	void setIsNegative(bool is_negative);//设置数是否为负数

	void simply();//简化数字，例：“000.0300”化简为“0.03”
	void setPrecision(const int& p);//保留有效数字

	std::string toString()const;//将数从链表转化为std::string类型
	static std::string to_string(const Number& number);//Number静态函数，接受一个Number类型数返回对应的std::string类型数


	Number slice(Node* start, Node* end, Number::sliceOption option);
	//根据方法，对链表从start结点到end结点的切片（不包含end结点），返回Number类型的一个数


	int countIntLen();//遍历链表，返回整数部分长度
	int countDecLen();//遍历链表，返回小数部分长度

	friend bool operator > (const Number& number1, const Number& number2);//比较两个数的大小
	friend Number operator + (const Number& number1, const Number& number2);//加法计算
	friend Number operator - (const Number& number1, const Number& number2);//减法计算
	friend Number operator * (const Number& number, Node* node);//单结点乘一个数
	friend Number operator * (const Number& number1, const Number& number2);//乘法计算
	friend Number operator / (const Number& number1, const Number& number2);//除法计算
	Number& operator = (const Number& number);//赋值（深赋值）
};

template<typename T>
inline std::string Number::to_string_with_precision(const T number, const int precision)
{
	int n = precision;
	std::ostringstream out;
	if (precision == -1)
	{
		out << std::fixed << std::setprecision(20) << number;
	}
	else
	{
		out << std::fixed << std::setprecision(n) << number;
	}
	return out.str();
}
