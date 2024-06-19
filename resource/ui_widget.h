/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_vice;
    QLineEdit *lineEdit_main;
    QGridLayout *gridLayout;
    QPushButton *btn_num4;
    QPushButton *btn_num3;
    QPushButton *btn_add;
    QPushButton *btn_multi;
    QPushButton *btn_equal;
    QPushButton *btn_num9;
    QPushButton *btn_num5;
    QPushButton *btn_div;
    QPushButton *btn_del;
    QPushButton *btn_numSign;
    QPushButton *btn_num7;
    QPushButton *btn_reciprocal;
    QPushButton *btn_C;
    QPushButton *btn_square;
    QPushButton *btn_num8;
    QPushButton *btn_squareRoot;
    QPushButton *btn_num2;
    QPushButton *btn_num1;
    QPushButton *btn_percentage;
    QPushButton *btn_numDot;
    QPushButton *btn_num6;
    QPushButton *btn_sub;
    QPushButton *btn_CE;
    QPushButton *btn_num0;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(320, 425);
        Widget->setMinimumSize(QSize(320, 425));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/calculator_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"border:none;\n"
"background-color: rgb(238, 236, 236);\n"
"}\n"
"\n"
"QPushButton \n"
"{	\n"
"background-color:rgb(243,243,243);\n"
"}\n"
"QPushButton:hover \n"
"{	\n"
"border:1px solid rgb(193,193,193);\n"
"background-color:rgb(221,223,221);\n"
"}\n"
"\n"
"QPushButton#btn_numSign, #btn_num0, #btn_numDot, #btn_num1, #btn_num2, #btn_num3, #btn_num4, #btn_num5, #btn_num6, #btn_num7, #btn_num8, #btn_num9 {\n"
"    background-color: rgb(252, 252, 252);\n"
"}\n"
"QPushButton#btn_num0, #btn_num1, #btn_num2, #btn_num3, #btn_num4, #btn_num5, #btn_num6, #btn_num7, #btn_num8, #btn_num9 {\n"
"    font: bold 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"    background-color: rgb(252, 252, 252);\n"
"}\n"
"/*\n"
"//\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\346\240\267\345\274\217\n"
"QPushButton#btn_numSign:hover,#btn_num0:hover,#btn_numDot:hover,#btn_num1:hover,#btn_num2:hover,#btn_num3:hover,#btn_num4:hover,#btn_num5:hover,#btn_num6:hover,#btn_num7:hover,#btn_num8:"
                        "hover,#btn_num9:hover\n"
"{	\n"
"border:1px solid rgb(193,193,193);\n"
"background-color:rgb(221,223,221);\n"
"}\n"
"*/\n"
"/* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\347\232\204\346\240\267\345\274\217 */\n"
"QPushButton#btn_num0:pressed,\n"
"QPushButton#btn_num1:pressed,\n"
"QPushButton#btn_num2:pressed,\n"
"QPushButton#btn_num3:pressed,\n"
"QPushButton#btn_num4:pressed,\n"
"QPushButton#btn_num5:pressed,\n"
"QPushButton#btn_num6:pressed,\n"
"QPushButton#btn_num7:pressed,\n"
"QPushButton#btn_num8:pressed,\n"
"QPushButton#btn_num9:pressed \n"
"{\n"
"    background-color: #ddd;  /* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"/* \347\246\201\347\224\250\347\212\266\346\200\201\344\270\213\347\232\204\346\240\267\345\274\217 */\n"
"QPushButton:disabled\n"
" {\n"
"    background-color: #eee;  /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    col"
                        "or: #888;  /* \347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"QLineEdit#lineEdit_vice {\n"
"    color: #808080; /* \346\267\261\347\201\260\350\211\262 */\n"
"}"));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_vice = new QLineEdit(Widget);
        lineEdit_vice->setObjectName("lineEdit_vice");
        lineEdit_vice->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_vice->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_vice, 0, 0, 1, 1);

        lineEdit_main = new QLineEdit(Widget);
        lineEdit_main->setObjectName("lineEdit_main");
        lineEdit_main->setMinimumSize(QSize(0, 70));
        QFont font;
        font.setPointSize(12);
        lineEdit_main->setFont(font);
        lineEdit_main->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_main->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_main, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, 4, -1, -1);
        btn_num4 = new QPushButton(Widget);
        btn_num4->setObjectName("btn_num4");
        btn_num4->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num4, 3, 0, 1, 1);

        btn_num3 = new QPushButton(Widget);
        btn_num3->setObjectName("btn_num3");
        btn_num3->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num3, 4, 2, 1, 1);

        btn_add = new QPushButton(Widget);
        btn_add->setObjectName("btn_add");
        btn_add->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_add, 4, 3, 1, 1);

        btn_multi = new QPushButton(Widget);
        btn_multi->setObjectName("btn_multi");
        btn_multi->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_multi, 2, 3, 1, 1);

        btn_equal = new QPushButton(Widget);
        btn_equal->setObjectName("btn_equal");
        btn_equal->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_equal, 5, 3, 1, 1);

        btn_num9 = new QPushButton(Widget);
        btn_num9->setObjectName("btn_num9");
        btn_num9->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num9, 2, 2, 1, 1);

        btn_num5 = new QPushButton(Widget);
        btn_num5->setObjectName("btn_num5");
        btn_num5->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num5, 3, 1, 1, 1);

        btn_div = new QPushButton(Widget);
        btn_div->setObjectName("btn_div");
        btn_div->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_div, 1, 3, 1, 1);

        btn_del = new QPushButton(Widget);
        btn_del->setObjectName("btn_del");
        btn_del->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_del, 0, 3, 1, 1);

        btn_numSign = new QPushButton(Widget);
        btn_numSign->setObjectName("btn_numSign");
        btn_numSign->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_numSign, 5, 0, 1, 1);

        btn_num7 = new QPushButton(Widget);
        btn_num7->setObjectName("btn_num7");
        btn_num7->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num7, 2, 0, 1, 1);

        btn_reciprocal = new QPushButton(Widget);
        btn_reciprocal->setObjectName("btn_reciprocal");
        btn_reciprocal->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_reciprocal, 1, 0, 1, 1);

        btn_C = new QPushButton(Widget);
        btn_C->setObjectName("btn_C");
        btn_C->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_C, 0, 2, 1, 1);

        btn_square = new QPushButton(Widget);
        btn_square->setObjectName("btn_square");
        btn_square->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_square, 1, 1, 1, 1);

        btn_num8 = new QPushButton(Widget);
        btn_num8->setObjectName("btn_num8");
        btn_num8->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num8, 2, 1, 1, 1);

        btn_squareRoot = new QPushButton(Widget);
        btn_squareRoot->setObjectName("btn_squareRoot");
        btn_squareRoot->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_squareRoot, 1, 2, 1, 1);

        btn_num2 = new QPushButton(Widget);
        btn_num2->setObjectName("btn_num2");
        btn_num2->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num2, 4, 1, 1, 1);

        btn_num1 = new QPushButton(Widget);
        btn_num1->setObjectName("btn_num1");
        btn_num1->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num1, 4, 0, 1, 1);

        btn_percentage = new QPushButton(Widget);
        btn_percentage->setObjectName("btn_percentage");
        btn_percentage->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_percentage, 0, 0, 1, 1);

        btn_numDot = new QPushButton(Widget);
        btn_numDot->setObjectName("btn_numDot");
        btn_numDot->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_numDot, 5, 2, 1, 1);

        btn_num6 = new QPushButton(Widget);
        btn_num6->setObjectName("btn_num6");
        btn_num6->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num6, 3, 2, 1, 1);

        btn_sub = new QPushButton(Widget);
        btn_sub->setObjectName("btn_sub");
        btn_sub->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_sub, 3, 3, 1, 1);

        btn_CE = new QPushButton(Widget);
        btn_CE->setObjectName("btn_CE");
        btn_CE->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_CE, 0, 1, 1, 1);

        btn_num0 = new QPushButton(Widget);
        btn_num0->setObjectName("btn_num0");
        btn_num0->setMinimumSize(QSize(75, 50));

        gridLayout->addWidget(btn_num0, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "calculator", nullptr));
        lineEdit_vice->setText(QString());
        lineEdit_main->setText(QCoreApplication::translate("Widget", "0", nullptr));
        btn_num4->setText(QCoreApplication::translate("Widget", "4", nullptr));
        btn_num3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        btn_add->setText(QCoreApplication::translate("Widget", "+", nullptr));
        btn_multi->setText(QCoreApplication::translate("Widget", "\303\227", nullptr));
        btn_equal->setText(QCoreApplication::translate("Widget", "=", nullptr));
        btn_num9->setText(QCoreApplication::translate("Widget", "9", nullptr));
        btn_num5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        btn_div->setText(QCoreApplication::translate("Widget", "\303\267", nullptr));
        btn_del->setText(QCoreApplication::translate("Widget", "del", nullptr));
        btn_numSign->setText(QCoreApplication::translate("Widget", "+/-", nullptr));
        btn_num7->setText(QCoreApplication::translate("Widget", "7", nullptr));
        btn_reciprocal->setText(QCoreApplication::translate("Widget", "1/x", nullptr));
        btn_C->setText(QCoreApplication::translate("Widget", "C", nullptr));
        btn_square->setText(QCoreApplication::translate("Widget", "x\302\262", nullptr));
        btn_num8->setText(QCoreApplication::translate("Widget", "8", nullptr));
        btn_squareRoot->setText(QCoreApplication::translate("Widget", "2\342\210\232x", nullptr));
        btn_num2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        btn_num1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        btn_percentage->setText(QCoreApplication::translate("Widget", "%", nullptr));
        btn_numDot->setText(QCoreApplication::translate("Widget", ".", nullptr));
        btn_num6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        btn_sub->setText(QCoreApplication::translate("Widget", "-", nullptr));
        btn_CE->setText(QCoreApplication::translate("Widget", "CE", nullptr));
        btn_num0->setText(QCoreApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
