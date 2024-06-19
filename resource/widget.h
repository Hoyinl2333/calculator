/*widget.h*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QVector>
#include"number.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class QAbstractButton;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);//Widget窗口构造函数
    ~Widget();//Widget窗口析构函数

    void initUi();//初始化ui界面

public slots:
    void onButtonGroupClicked(QAbstractButton*btn);//槽函数，当按钮组被点击时执行

private:
    Ui::Widget *ui;//ui界面指针
    QVector<QVariant> vec;//存储整个运算的变量（左操作数、操作符、右操作数、等于号、计算结果）
    QMap<QString,int> map;//便于管理vec,提升代码可读性
    QString preBtn;//上一次点击的按钮

    //实现计算
    Number m_num1;//左操作数
    Number m_num2;//右操作数
    Number m_numResult;//计算结果

};
#endif // WIDGET_H
