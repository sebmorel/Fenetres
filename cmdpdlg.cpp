#include "cmdpdlg.h"
#include "ui_cmdpdlg.h"

#include <QWidget>
#include <QString>
#include <QLineEdit>

CMdpDlg::CMdpDlg(QWidget *parent, QString mdp) :
    CDialog(parent),
    ui(new Ui::CMdpDlg)
{
    ui->setupUi(this);
    ui->editMdp->setEchoMode(QLineEdit::Password);
    m_mdp = mdp;
    connect(ui->pushOK, SIGNAL(clicked()), this, SLOT(onPushOKClicked()));
    connect(ui->pushCancel, SIGNAL(clicked()), this, SLOT(onPushCancelClicked()));
}

CMdpDlg::~CMdpDlg()
{
    delete ui;
}

void CMdpDlg::onPushOKClicked()
{
    if (ui->editMdp->text() == m_mdp) accept();
    else CMessageBox::critical(this, "Erreur", "Mot de passe erroné.", CMessageBox::Ok, CMessageBox::NoButton);
}

void CMdpDlg::onPushCancelClicked()
{
    reject();
}
