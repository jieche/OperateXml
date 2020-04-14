/********************************************************************************
** Form generated from reading UI file 'operatexml.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATEXML_H
#define UI_OPERATEXML_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperateXmlClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QTableView *tableView;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_lon;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_lat;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OperateXmlClass)
    {
        if (OperateXmlClass->objectName().isEmpty())
            OperateXmlClass->setObjectName(QStringLiteral("OperateXmlClass"));
        OperateXmlClass->resize(631, 360);
        centralWidget = new QWidget(OperateXmlClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 571, 261));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_5->addWidget(tableView, 0, 0, 4, 1);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget, 0, 1, 1, 1);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_lon = new QLineEdit(widget_2);
        lineEdit_lon->setObjectName(QStringLiteral("lineEdit_lon"));

        gridLayout_2->addWidget(lineEdit_lon, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_2, 1, 1, 1, 1);

        widget_3 = new QWidget(layoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_lat = new QLineEdit(widget_3);
        lineEdit_lat->setObjectName(QStringLiteral("lineEdit_lat"));

        gridLayout_3->addWidget(lineEdit_lat, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_3, 2, 1, 1, 1);

        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_add = new QPushButton(widget_4);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout_4->addWidget(pushButton_add, 0, 0, 1, 1);

        pushButton_del = new QPushButton(widget_4);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));

        gridLayout_4->addWidget(pushButton_del, 1, 0, 1, 1);


        gridLayout_5->addWidget(widget_4, 3, 1, 1, 1);

        OperateXmlClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OperateXmlClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 26));
        OperateXmlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OperateXmlClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OperateXmlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OperateXmlClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OperateXmlClass->setStatusBar(statusBar);

        retranslateUi(OperateXmlClass);

        QMetaObject::connectSlotsByName(OperateXmlClass);
    } // setupUi

    void retranslateUi(QMainWindow *OperateXmlClass)
    {
        OperateXmlClass->setWindowTitle(QApplication::translate("OperateXmlClass", "OperateXml", Q_NULLPTR));
        label->setText(QApplication::translate("OperateXmlClass", "\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("OperateXmlClass", "\347\273\217\345\272\246\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("OperateXmlClass", "\347\272\254\345\272\246\357\274\232", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("OperateXmlClass", "\346\267\273\345\212\240\345\205\245\345\210\227\350\241\250", Q_NULLPTR));
        pushButton_del->setText(QApplication::translate("OperateXmlClass", "\345\210\240\351\231\244\351\200\211\344\270\255\351\241\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OperateXmlClass: public Ui_OperateXmlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATEXML_H
