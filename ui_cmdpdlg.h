/********************************************************************************
** Form generated from reading UI file 'cmdpdlg.ui'
**
** Created: Tue 6. Nov 08:55:14 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMDPDLG_H
#define UI_CMDPDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CMdpDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *editMdp;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushOK;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushCancel;

    void setupUi(QDialog *CMdpDlg)
    {
        if (CMdpDlg->objectName().isEmpty())
            CMdpDlg->setObjectName(QString::fromUtf8("CMdpDlg"));
        CMdpDlg->resize(282, 111);
        verticalLayout = new QVBoxLayout(CMdpDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CMdpDlg);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        editMdp = new QLineEdit(CMdpDlg);
        editMdp->setObjectName(QString::fromUtf8("editMdp"));
        editMdp->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(editMdp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushOK = new QPushButton(CMdpDlg);
        pushOK->setObjectName(QString::fromUtf8("pushOK"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushOK->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/bullet_accept"), QSize(), QIcon::Normal, QIcon::Off);
        pushOK->setIcon(icon);
        pushOK->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushOK);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushCancel = new QPushButton(CMdpDlg);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/root/bullet_deny"), QSize(), QIcon::Normal, QIcon::Off);
        pushCancel->setIcon(icon1);
        pushCancel->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CMdpDlg);

        QMetaObject::connectSlotsByName(CMdpDlg);
    } // setupUi

    void retranslateUi(QDialog *CMdpDlg)
    {
        CMdpDlg->setWindowTitle(QApplication::translate("CMdpDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CMdpDlg", "Veuillez saisir le mot de passe", 0, QApplication::UnicodeUTF8));
        pushOK->setText(QApplication::translate("CMdpDlg", "OK", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("CMdpDlg", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMdpDlg: public Ui_CMdpDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDPDLG_H
