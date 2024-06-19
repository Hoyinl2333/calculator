/*widget.cpp*/

#include "widget.h"
#include "ui_widget.h"
#include<QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initUi();
}

Widget::~Widget()
{

    delete ui;
}



void Widget::initUi()
{
    //创建map
    map.insert("number1",0);
    map.insert("operator",1);
    map.insert("number2",2);
    map.insert("equal",3);
    map.insert("result",4);
    //把所有按钮放在一个按钮组
    auto buttonGroup = new QButtonGroup(this);
    auto btnList = findChildren<QPushButton*>();
    for(auto btn :btnList)
    {
        buttonGroup->addButton(btn);
    }
    //初始化vec容器
    vec.resize(5);//vec数组存放【1.左操作数 2.操作符 3.右操作数 4.等于号 5.结果】

    //未实现功能“2√x”(todo)
    ui->btn_squareRoot->setEnabled(false);
    ui->btn_squareRoot->setToolTip("相关功能待完善");
    //是否已经添加小数点

    //关联按钮组的点击信号
    connect(buttonGroup,&QButtonGroup::buttonClicked,this,&Widget::onButtonGroupClicked);

}

void Widget::onButtonGroupClicked(QAbstractButton *btn)
{
    QString val = ui->lineEdit_main->text();
    QString name = btn->text();//获取当前按钮



    //处理按钮
    if(name.length() < 2 && ((name >= '0' && name <= '9') || name == "."))//这里如果没有name.length()<2的判断"1/x"会误判
    {
        
        if(ui->lineEdit_main->text()=="0"&&name!=".")//刚开始为0情况
        {
            ui->lineEdit_main->clear();
        }
        if (ui->lineEdit_main->text() == "-0" && name != ".")//刚开始为-0情况
        {
            ui->lineEdit_main->setText("-");
        }
        if(preBtn=="+"||preBtn=="-"||preBtn=="×"||preBtn=="÷")
        {
            ui->lineEdit_main->clear();
        }

        if (name == ".")
        {
            QString text = ui->lineEdit_main->text();
            bool hasDot = false;
            for (auto ch : text)
            {
                if (ch == '.')
                {
                    hasDot = true;
                }
            }
            if (!hasDot)
            {
                ui->lineEdit_main->insert(name);
            }
        }
        else
        {
            ui->lineEdit_main->insert(name);
        }
    }
    else if(name=="+/-")
    {
        QString currentText = ui->lineEdit_main->text(); // 获取当前文本
        if (!currentText.isEmpty())// 如果文本不为空且不以负号开头，则添加负号
        {
            if(currentText[0]!='-')
            {
                ui->lineEdit_main->setText('-' + currentText);
            }
            else
            {
                ui->lineEdit_main->setText(currentText.mid(1));
            }
        }
    }
    else if(name=="C")
    {
        ui->lineEdit_main->setText("0");
        ui->lineEdit_vice->clear();
        vec.clear();
        vec.resize(5);//清理vec容器
        auto btnList = findChildren<QPushButton*>();
        for (auto button :btnList)
        {
            if(button->text()!="C")
            {
                button->setEnabled(true); // 启用每个按钮
            }
        }
        //未实现功能“2√x”(todo)
        ui->btn_squareRoot->setEnabled(false);
    }
    else if(name=="CE")
    {
        ui->lineEdit_main->setText("0");
    }
    else if(name=="del")
    {
        ui->lineEdit_main->setCursorPosition(ui->lineEdit_main->cursorPosition()-1);
        ui->lineEdit_main->del();
        if(ui->lineEdit_main->text().isEmpty())
        {
            ui->lineEdit_main->setText("0");
        }
    }
    else if(name.length()<2&&(name=="+"||name=="-"||name=="×"||name=="÷"))
    {
        //存入左操作数和操作符
        vec[map.value("number1")] = val;
        vec[map.value("operator")] = name;
    }
    else if(name=="=")
    {
        vec[map.value("number2")] = val;
        vec[map.value("equal")] = "=";
        //计算大数，
        m_num1 = Number(vec[map.value("number1")].toString().toStdString());
        qDebug()<<"m_num1 = "+m_num1.toString();

        m_num2 = Number(vec[map.value("number2")].toString().toStdString());
        qDebug()<<"m_num2 = "+m_num2.toString();



        if(vec[map.value("operator")]=="+")
        {
            m_numResult = m_num1 + m_num2;
        }
        if(vec[map.value("operator")]=="-")
        {
            m_numResult = m_num1 - m_num2;
        }
        if(vec[map.value("operator")]=="×")
        {
            m_numResult = m_num1 * m_num2;
        }
        if(vec[map.value("operator")]=="÷")
        {
            if(val.toDouble()!=0)//除数不为0
            {
                m_numResult = m_num1 / m_num2;
            }
        }
        //除数是0的在文本框的显示
        if(abs(val.toDouble())>=0)
        {
            qDebug()<<"m_numResult = "+m_numResult.toString();
            vec[map.value("result")] =QString::fromStdString(m_numResult.toString());
            ui->lineEdit_main->setText(vec[map.value("result")].toString());
        }
        else
        {
            ui->lineEdit_main->setText("divide zero error!");
        }
    }
    else if(name=="x²")
    {
        m_num1 = m_num2= Number(val.toStdString());
        m_numResult = m_num1*m_num2;
        QString result = QString::fromStdString(m_numResult.toString());
        if(vec[map.value("operator")].isNull())
        {
            vec[map.value("number1")] = result;
        }
        else
        {
            vec[map.value("number2")] = result;
        }
        ui->lineEdit_main->setText(result);
    }
    else if(name=="1/x")
    {
        if(val!="0")
        {
            m_num1 = 1;
            m_num2 = Number(val.toStdString());
            m_numResult = m_num1/m_num2;
            QString result = QString::fromStdString(m_numResult.toString());
            qDebug()<<result;
            if(vec[map.value("operator")].isNull())
            {
                vec[map.value("number1")] = result;
            }
            else
            {
                vec[map.value("number2")] = result;
            }
            ui->lineEdit_main->setText(result);
        }
        else
        {
            ui->lineEdit_main->setText("divide zero error!");
        }
    }
    else if(name=="%")
    {
        QString result;
        if(vec[map.value("operator")].isNull())
        {
            result = "0";
            vec[map.value("number1")] = result;
            qDebug()<<vec[map.value("number1")].toString();
        }
        else
        {
            m_num1 = Number(vec[map.value("number1")].toString().toStdString());
            m_num2 = Number(val.toStdString())/100;
            m_numResult = m_num1 * m_num2;
            result = QString::fromStdString(m_numResult.toString());
            qDebug()<<result;
            vec[map.value("number2")] = result;
        }
        ui->lineEdit_main->setText(result);
    }

    //在lineEdit_vice显示表达式
    if(name=="+"||name=="-"||name=="×"||name=="÷")
    {
        ui->lineEdit_vice->clear();
        for(qsizetype i = 0;i<2&&i<vec.size();++i)
        {
            qDebug()<<vec[i].toString();
            ui->lineEdit_vice->insert(vec[i].toString());
        }

    }
    if(name=="=")
    {
        ui->lineEdit_vice->clear();
        for(qsizetype i = 0;i<4&&i<vec.size();++i)
        {
            ui->lineEdit_vice->insert(vec[i].toString());
        }
    }
    if(name=="x²")
    {
        ui->lineEdit_vice->clear();
        for(qsizetype i = 0;i<4&&!vec[i].isNull();i++)
        {
            ui->lineEdit_vice->insert(vec[i].toString());
        }
    }
    if(name=="1/x")
    {
        ui->lineEdit_vice->clear();
        if(val.toDouble()!=0)
        {
            for(qsizetype i = 0;i<4&&!vec[i].isNull();i++)
            {
                ui->lineEdit_vice->insert(vec[i].toString());
            }
        }
    }
    if(name=="%")
    {
        ui->lineEdit_vice->clear();
        for(qsizetype i = 0;i<4&&!vec[i].isNull();i++)
        {
            ui->lineEdit_vice->insert(vec[i].toString());
        }

    }
    if(ui->lineEdit_main->text()=="divide zero error!")//当前主文本框的内容为“divide zero error!”
    {
        auto btnList = findChildren<QPushButton*>();
        for (auto button :btnList)
        {
            if(button->text()!="C")
            {
                button->setEnabled(false); // 禁用每个按钮
            }
        }
    }
    preBtn  = name;
    qDebug()<<preBtn;
}
