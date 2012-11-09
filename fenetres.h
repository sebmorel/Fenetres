#ifndef FENETRES_H
#define FENETRES_H

#include "Fenetres_global.h"

#include <QMainWindow>
#include <QDialog>
#include <ctcpclient.h>
#include <QMessageBox>
#include "ctcpretour.h"

class CSql;
class CMessageBox;
class CTcpClient;
class QVariant;
class QStringList;

class CMainWindow;

void FENETRESSHARED_EXPORT RestaureDimWin(QWidget *win, QString strDimWin);
QString FENETRESSHARED_EXPORT SauveDimWin(QWidget *win, QString strDimWin);

class FENETRESSHARED_EXPORT CAbstractDialog
{
    friend class CDialog;
    friend class CMainWindow;
public:
    CAbstractDialog();
    ~CAbstractDialog();

    void tcpConnect();
    CTcpClient *socket();
    CMessageBox *messageBox();
    void tcpSendMessage(QString message, QString balise);
    CSql *db();
    void sqlRequete(QString requete);
    bool sqlExec();
    bool sqlNext();
    bool sqlIsValid();
    bool sqlSeek(int pos);
    QVariant sqlValue(int pos);
    QStringList connectedPostes();

//    void setPoste(QString poste);
    QString poste();
//    void setTypeParent(QString parent);
//    QString typeParent();
//    CTcpClient *m_socket;
//    void tcpConnect();
private:
    CTcpClient  *_socket;
    CSql        *_db;
//    CMessageBox *_msgbox;
    quint32     m_tailleMsg;
    QString     m_poste;

    void newSocket(CMainWindow *parent);
    void newDB();
//    QString _typeParent;
//protected:
//    void setSocket(CTcpClient *socket);

//private slots:
    virtual void donneesRecues();
    virtual void connecte();
    virtual void deconnecte();
    virtual void erreurSocket(QAbstractSocket::SocketError erreur);
    virtual void stateSocket(QAbstractSocket::SocketState etat);
////private slots:
//    void donneesRecues();
//    void connecte();
////    void deconnecte();
//    void erreurSocket(QAbstractSocket::SocketError erreur);
};


/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
class FENETRESSHARED_EXPORT CDialog : public QDialog, public CAbstractDialog
{
    Q_OBJECT
public:
    explicit CDialog(QWidget *parent=0);
    ~CDialog();

//    void setSocket(CTcpClient *socket);
//    CTcpClient *socket();
//    void setPoste(QString poste);
//    QString poste();
    void tcpConnect();
//    void tcpSendMessage(QString message, QString balise);
    QString dialogType();
//    void connectTcpEvt();

private:
    QString     _typeDialog;
//    QString     m_poste;
//    CTcpClient  *m_socket;
    quint32     m_tailleMsg;
//    QMessageBox *_msgBox;

//private slots:
//    virtual void donneesRecues();
//    virtual void connecte();
//    virtual void deconnecte();
//    virtual void erreurSocket(QAbstractSocket::SocketError erreur);
//    virtual void stateSocket(CTcpClient::SocketState etat);
};


/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
class FENETRESSHARED_EXPORT CMainWindow : public QMainWindow, public CAbstractDialog
{
    Q_OBJECT
    friend class CDialog;
public:
    explicit CMainWindow(QWidget *parent=0);
    ~CMainWindow();

    void setSocket(CTcpClient *socket);
//    CTcpClient *socket();
    void setPoste(QString poste);
//    QString poste();
//    void tcpSendMessage(QString message, QString balise);
    QString dialogType();

private:
    QString     _typeDialog;
    CMessageBox *_msgbox;
//    QMessageBox *_msgBox;

protected:
//    QString m_poste;
//    CTcpClient  *m_socket;

private slots:
    void donneesRecues();
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);
    void stateSocket(QAbstractSocket::SocketState etat);

};
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
class FENETRESSHARED_EXPORT CMessageBox : public QMessageBox
{
    Q_OBJECT

public:
    explicit CMessageBox();
    CMessageBox(QWidget *parent);
    CMessageBox(Icon icon, const QString &title, const QString &text, StandardButtons boutons=NoButton, QWidget *parent=0, Qt::WindowFlags f=0);
    CMessageBox(TypesRetour::TypeMessage icon, const QString &title, const QString &text,
                             int boutons=0, QWidget *parent=0, Qt::WindowFlags f=0);
    ~CMessageBox();
//    CMessageBox(QWidget *parent, QString title, QString message);
//    CMessageBox(const QString &title, const QString &message, Icon icon, int button1, int button2, int button3, QWidget *parent, Qt::WindowFlags f=0);
//    CMessageBox(Icon icon, const QString &title, const QString &text, StandardButtons buttons=NoButton, QWidget *parent=0, Qt::WindowFlags f=Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
};

#endif // FENETRES_H
