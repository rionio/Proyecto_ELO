/********************************************************************************
** Form generated from reading UI file 'graficadora.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICADORA_H
#define UI_GRAFICADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graficadora
{
public:
    QAction *actionSalir;
    QAction *actionNormal;
    QAction *actionResize;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *input;
    QLabel *searchLabel;
    QPushButton *pushButton;
    QLabel *ejemplo;
    QGroupBox *groupBox_2;
    QPlainTextEdit *Rsolu;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuGraficos;

    void setupUi(QMainWindow *Graficadora)
    {
        if (Graficadora->objectName().isEmpty())
            Graficadora->setObjectName(QString::fromUtf8("Graficadora"));
        Graficadora->resize(654, 552);
        actionSalir = new QAction(Graficadora);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionNormal = new QAction(Graficadora);
        actionNormal->setObjectName(QString::fromUtf8("actionNormal"));
        actionResize = new QAction(Graficadora);
        actionResize->setObjectName(QString::fromUtf8("actionResize"));
        centralwidget = new QWidget(Graficadora);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 631, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(verticalLayoutWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setEnabled(true);

        verticalLayout->addWidget(customPlot);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 410, 401, 71));
        groupBox->setTitle(QString::fromUtf8(""));
        groupBox->setFlat(true);
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        input = new QLineEdit(groupBox);
        input->setObjectName(QString::fromUtf8("input"));

        gridLayout->addWidget(input, 4, 1, 1, 1);

        searchLabel = new QLabel(groupBox);
        searchLabel->setObjectName(QString::fromUtf8("searchLabel"));

        gridLayout->addWidget(searchLabel, 4, 0, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 2, 1, 1);

        ejemplo = new QLabel(groupBox);
        ejemplo->setObjectName(QString::fromUtf8("ejemplo"));

        gridLayout->addWidget(ejemplo, 1, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(430, 410, 201, 91));
        groupBox_2->setFlat(true);
        Rsolu = new QPlainTextEdit(groupBox_2);
        Rsolu->setObjectName(QString::fromUtf8("Rsolu"));
        Rsolu->setGeometry(QRect(10, 20, 181, 61));
        Rsolu->setReadOnly(true);
        Graficadora->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Graficadora);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Graficadora->setStatusBar(statusbar);
        menubar = new QMenuBar(Graficadora);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 654, 19));
        menuGraficos = new QMenu(menubar);
        menuGraficos->setObjectName(QString::fromUtf8("menuGraficos"));
        Graficadora->setMenuBar(menubar);
#if QT_CONFIG(shortcut)
        searchLabel->setBuddy(input);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuGraficos->menuAction());
        menuGraficos->addAction(actionSalir);

        retranslateUi(Graficadora);
        QObject::connect(actionSalir, SIGNAL(triggered()), Graficadora, SLOT(close()));

        QMetaObject::connectSlotsByName(Graficadora);
    } // setupUi

    void retranslateUi(QMainWindow *Graficadora)
    {
        Graficadora->setWindowTitle(QCoreApplication::translate("Graficadora", "Graficadora", nullptr));
        actionSalir->setText(QCoreApplication::translate("Graficadora", "Salir", nullptr));
        actionNormal->setText(QCoreApplication::translate("Graficadora", "Normal", nullptr));
        actionResize->setText(QCoreApplication::translate("Graficadora", "Resize", nullptr));
        input->setText(QString());
        searchLabel->setText(QCoreApplication::translate("Graficadora", "f[x]=", nullptr));
        pushButton->setText(QCoreApplication::translate("Graficadora", "Generate", nullptr));
        ejemplo->setText(QCoreApplication::translate("Graficadora", "Sintaxis: ax^n\302\261bx^(n-1)\302\261...\302\261c    (a,b,c\342\210\212Z \342\210\251 n\342\210\212N)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Graficadora", "Soluciones", nullptr));
        menuGraficos->setTitle(QCoreApplication::translate("Graficadora", "Graficos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graficadora: public Ui_Graficadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICADORA_H
