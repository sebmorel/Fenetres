#include "fenetres.h"

#include <QMessageBox>
#include <QVariant>
#include <QStringList>
#include <QAbstractButton>

#include "ctcpclient.h"
#include "CSql.h"
//#include "ctcpretour.h"
#include "tcpfonctions.h"
#include "globalesfonctions.h"

// Bibliothèques C.
#include <iostream>
#include <fstream>

/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
CAbstractDialog::CAbstractDialog()
{
    _socket = NULL;
    _db = NULL;
}
CAbstractDialog::~CAbstractDialog()
{
}
CTcpClient *CAbstractDialog::socket(){
    return _socket;
}
//CMessageBox *CAbstractDialog::messageBox(){
//    return _msgbox;
//}
void CAbstractDialog::tcpSendMessage(QString message, QString balise=QString::null)
{
    _socket->sendMessage( message, balise);
}
void CAbstractDialog::newSocket(CMainWindow *parent){
    _socket = new CTcpClient(parent);
}
void CAbstractDialog::newDB(){
    _db = new CSql(socket());
}
CSql *CAbstractDialog::db(){
    return _db;
}
void CAbstractDialog::sqlRequete(QString requete){
    _socket->sqlRequete(requete);
}
bool CAbstractDialog::sqlExec(){
    return _socket->sqlExec();
}
bool CAbstractDialog::sqlNext(){
    return _socket->sqlNext();
}
bool CAbstractDialog::sqlIsValid(){
    return _socket->sqlIsValid();
}
bool CAbstractDialog::sqlSeek(int pos){
    return _socket->sqlSeek(pos);
}
QVariant CAbstractDialog::sqlValue(int pos){
    return _socket->sqlValue(pos);
}
/************************************************************************************************/
void CAbstractDialog::tcpConnect()
{
    _fctTcpConnexion(_socket);
}
/************************************************************************************************/
void CAbstractDialog::donneesRecues()
{
    CMessageBox *box;
    CTcpRetour retour = _evtTcpDonneesRecues(_socket, &m_tailleMsg);
    if (!retour.isNull()){
//    if (TypesRetour::None != retour.typeMessage()){
        box = new CMessageBox(retour.typeMessage(), retour.titre(), retour.message(), retour.boutons(), NULL,
                              Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
//        box = new CMessageBox(CMessageBox::Information, retour.titre(), retour.message(), retour.boutons(), this,
//                              Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
        box->show();
    }
}
/************************************************************************************************/
void CAbstractDialog::connecte(){
    _evtTcpConnecte(_socket);
}
/************************************************************************************************/
void CAbstractDialog::deconnecte(){
    _evtTcpDeco(_socket);
}
/************************************************************************************************/
void CAbstractDialog::erreurSocket(CTcpClient::SocketError erreur){
//    _evtTcpErreur(_socket, erreur, this);
}
/************************************************************************************************/
void CAbstractDialog::stateSocket(CTcpClient::SocketState etat){
//    _evtTcpStateChange(_socket, etat, &_msgbox, this);
}
/************************************************************************************************/
QStringList CAbstractDialog::connectedPostes()
{
    return _socket->connectedPostes();
}
//void CAbstractDialog::setPoste(QString poste){
//    m_poste = poste;
//}
QString CAbstractDialog::poste(){
    return m_poste;
}
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/

/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
CDialog::CDialog(QWidget *parent) :
    QDialog(parent), CAbstractDialog()
{
    if (NULL != parent){
        if ("CDialog" == parent->accessibleDescription()){
            _socket = ((CDialog*)parent)->socket();
            _db = ((CDialog*)parent)->db();
            m_poste = ((CDialog*)parent)->poste();
        }
        else if ("CMainWindow" == parent->accessibleDescription()){
            _socket = ((CMainWindow*)parent)->socket();
            _db = ((CMainWindow*)parent)->db();
            m_poste = ((CMainWindow*)parent)->poste();
        }
    }
    setAccessibleDescription("CDialog");
}

/************************************************************************************************/
CDialog::~CDialog()
{
}
/************************************************************************************************/
void CDialog::tcpConnect()
{
    _fctTcpConnexion(_socket);
}
/************************************************************************************************/
QString CDialog::dialogType()
{
    return accessibleDescription();
}
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent), CAbstractDialog()
{
    setAccessibleDescription("CMainWindow");
    m_tailleMsg = 0;
    newSocket(this);
    newDB();
    _msgbox = NULL;
    connect(_socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(_socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    connect(_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateSocket(QAbstractSocket::SocketState)));
}
/************************************************************************************************/
CMainWindow::~CMainWindow()
{
}
/************************************************************************************************/
void CMainWindow::setPoste(QString poste){
    m_poste = poste;
}
/************************************************************************************************/
QString CMainWindow::dialogType()
{
    return accessibleDescription();
}
/************************************************************************************************/
void CMainWindow::donneesRecues()
{
    CMessageBox *box;
    CTcpRetour retour = _evtTcpDonneesRecues(_socket, &m_tailleMsg);
    if (!retour.isNull()){
        box = new CMessageBox(retour.typeMessage(), retour.titre(), retour.message(), retour.boutons(), this,
                              Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
        box->show();
    }
}
/************************************************************************************************/
void CMainWindow::connecte(){
    _evtTcpConnecte(_socket);
}
/************************************************************************************************/
void CMainWindow::deconnecte(){
    _evtTcpDeco(_socket);
}
/************************************************************************************************/
void CMainWindow::erreurSocket(CTcpClient::SocketError erreur){
    int iChoix;
    CMessageBox *box;
    CTcpRetour retour = _evtTcpErreur(_socket, erreur/*, this*/);
//    if(!retour.isNull()){
    box = new CMessageBox(retour.typeMessage(), retour.titre(), retour.message(), retour.boutons(), this,
                      Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint);
    iChoix = box->exec();
    switch (iChoix){
    case (CMessageBox::Retry):
        _socket->reset();
        _socket->connectToHost(cfgLecture("SERVEUR", "ip"), cfgLecture("SERVEUR", "port").toInt());
        break;

    case (CMessageBox::Close):
        parentWidget()->close();
        break;
    }
    delete box;
}
/************************************************************************************************/
void CMainWindow::stateSocket(CTcpClient::SocketState etat){
    CTcpRetour retour = _evtTcpStateChange(_socket, etat/*, &_msgbox, this*/);

    if (NULL != _msgbox){
        _msgbox->close();
        delete (_msgbox);
        _msgbox = NULL;
    }
    if (!retour.isNull()){
        _msgbox = new CMessageBox(retour.typeMessage(), retour.titre(), retour.message(), retour.boutons(), this);
        _msgbox->show();
    }
}
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
CMessageBox::CMessageBox() :
    QMessageBox()
{
}
/************************************************************************************************/
CMessageBox::CMessageBox(QWidget *parent) :
    QMessageBox(parent)
{
}
/************************************************************************************************/
CMessageBox::CMessageBox(Icon icon, const QString &title, const QString &text, StandardButtons boutons, QWidget *parent, Qt::WindowFlags f)
    : QMessageBox(icon, title, text, boutons, parent, f)
{
    std::cout << "-2-" << boutons << std::endl;
    if(boutons == CMessageBox::NoButton){
        foreach(QAbstractButton *but, buttons()) but->hide();
    }
}
CMessageBox::CMessageBox(TypesRetour::TypeMessage icon, const QString &title, const QString &text,
                         int boutons, QWidget *parent, Qt::WindowFlags f)
    : QMessageBox((Icon)icon, title, text, (StandardButtons)boutons, parent, f)
{
    std::cout << "-1-" << boutons << std::endl;
    if((StandardButtons)boutons == CMessageBox::NoButton){
        foreach(QAbstractButton *but, buttons()) but->hide();
    }
}

/************************************************************************************************/
CMessageBox::~CMessageBox()
{
}

/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
void RestaureDimWin(QWidget *win, QString strDimWin)
{
    if (QString::null != strDimWin){
        win->resize(strDimWin.split(";").at(0).toInt(), strDimWin.split(";").at(1).toInt());
        ("1" == strDimWin.split(";").at(2)) ? win->showMaximized() : win->showNormal();
    }
}
/************************************************************************************************/
QString SauveDimWin(QWidget *win, QString strDimWin)
{
    // Sauvegarde taille de la fenêtre.
    QString strNum;
    QStringList lstDimWin;
    QSize sizeWin = win->size();
    if (strDimWin.isNull() || strDimWin.isEmpty()) strDimWin = "800;600;0";
    lstDimWin = strDimWin.split(";");
    if (!win->isMaximized()){
        lstDimWin .replace(0, strNum.setNum(sizeWin.width()));
        lstDimWin .replace(1, strNum.setNum(sizeWin.height()));
    }
    lstDimWin .replace(2, strNum.setNum(win->isMaximized()));
    return lstDimWin.join(";");
}
/************************************************************************************************/

