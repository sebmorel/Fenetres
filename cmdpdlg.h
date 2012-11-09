#ifndef CMDPDLG_H
#define CMDPDLG_H
#include "fenetres.h"

namespace Ui {
    class CMdpDlg;
}

class FENETRESSHARED_EXPORT CMdpDlg : public CDialog
{
    Q_OBJECT

public:
    explicit CMdpDlg(QWidget *parent, QString mdp="vincentestdieu");
    ~CMdpDlg();

private:
    Ui::CMdpDlg *ui;
    QString m_mdp;

private slots:
    void onPushOKClicked();
    void onPushCancelClicked();
};

#endif // CMDPDLG_H
