#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfont.h"
#include "QPushButton"
#include "QDebug"
#include <algorithm>
#include <string>
#include <iostream>
#define scan this->ui->Scanner
using namespace std;
bool symbol = false;
bool deadScan = false;
long long startDigit = -1;
long long endDigit = -1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,550);
}

MainWindow::~MainWindow()
{
    delete ui;
}


long long toDigit(QString s){
    return s.toLongLong();
}
QString toString(long long digit){
    string ans = "";
    bool fg = 0;
    if(digit == 0)
        ans = "0";
    if(digit<0)
        fg=1,digit*=-1;
    while(digit){
        ans += digit%10+'0';
        digit/=10;
    }
    if(fg)
        ans+='-';
    reverse(ans.begin(),ans.end());
    return QString::fromLocal8Bit(ans.data());
}
QString getChar(int flag){
    switch(flag){
    case 1:return "＋";break;
    case 2:return "－";break;
    case 3:return "×";break;
    case 4:return "÷";break;
    default:break;
    }
    return "";
}
void MainWindow::Calculate(QString str,int flag){
    QString c;
    for(int i=0,len=str.size();i<len;++i)
        if(!(str[i]>='0'&&str[i]<='9') && i!=0 ){
            c=str[i];
            break;
        }
    QStringList vector =  str.split(c);
    startDigit = toDigit(vector[0]);
    endDigit = toDigit(vector[1]);
    if(flag)
        symbol = true;
   // qDebug()<<symbol;
    if(c=="＋")
        scan->setText( toString(startDigit+endDigit) + getChar(flag));
    else if(c=="－")
        scan->setText( toString(startDigit-endDigit)+ getChar(flag));
    else if(c=="×")
        scan->setText( toString(startDigit*endDigit)+ getChar(flag));
    else if(c=="÷"){
        if(endDigit==0){
            scan->setText("Error");
            deadScan = true;
            return ;
        }
        scan->setText( toString(startDigit/endDigit)+ getChar(flag));
    }
    return ;
}
void MainWindow::on_btnOne_clicked()
{

    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("1"),symbol = false;
    else {
        scan->setText(scan->text()+"1");
    }


}

void MainWindow::on_btnTwo_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("2"),symbol = false;
    else {
        scan->setText(scan->text()+"2");
    }
}

void MainWindow::on_btnThree_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("3"),symbol = false;
    else {
        scan->setText(scan->text()+"3");
    }
}

void MainWindow::on_btnFour_clicked()
{

    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("4"),symbol = false;
    else {
        scan->setText(scan->text()+"4");
    }
}

void MainWindow::on_btnFive_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("5"),symbol = false;
    else {
        scan->setText(scan->text()+"5");
    }
}

void MainWindow::on_btnSix_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("6"),symbol = false;
    else {
        scan->setText(scan->text()+"6");
    }
}

void MainWindow::on_btnSeven_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("7"),symbol = false;
    else {
        scan->setText(scan->text()+"7");
    }
}

void MainWindow::on_btnEight_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("8"),symbol = false;
    else {
        scan->setText(scan->text()+"8");
    }
}

void MainWindow::on_btnNive_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("9"),symbol = false;
    else {
        scan->setText(scan->text()+"9");
    }
}

void MainWindow::on_btnZero_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(scan->text()=="0")
        scan->setText("0"),symbol = false;
    else {
        scan->setText(scan->text()+"0");
    }
}

void MainWindow::on_btnDiv_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(symbol == false){
        scan->setText(scan->text()+"÷");
        symbol = true;
    }
    else{
        QString str = scan->text();
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            return ;
        Calculate(str,4);
        startDigit = endDigit = -1;
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            symbol = false;
    }

}

void MainWindow::on_btnMul_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(symbol == false){
        scan->setText(scan->text()+"×");
        symbol = true;
    }
    else{
        QString str = scan->text();
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            return ;
        Calculate(str,3);
        startDigit = endDigit = -1;
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            symbol = false;
    }
}

void MainWindow::on_btnSub_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(symbol == false){
        scan->setText(scan->text()+"－");
        symbol = true;
    }
    else{
        QString str = scan->text();
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            return ;
        Calculate(str,2);
        startDigit = endDigit = -1;
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            symbol = false;
    }

}

void MainWindow::on_btnAdd_clicked()
{
    if(deadScan)
        return;
    if(scan->text().size()==13){
        scan->setText("超出限制");
        deadScan = true;
        return ;
    }
    if(symbol == false){
        scan->setText(scan->text()+"＋");
        symbol = true;
    }
    else{
        QString str = scan->text();
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            return ;
        Calculate(str,1);
        startDigit = endDigit = -1;
        if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
            symbol = false;
    }
}

void MainWindow::on_btnEqu_clicked()
{
    QString str = scan->text();

    if(!(str[str.size()-1]>='0'&&str[str.size()-1]<='9'))
        str+="0";

    Calculate(str,0);
    startDigit = endDigit = -1;
    symbol = false;
}

void MainWindow::on_btnCal_clicked()
{
    this->ui->Scanner->setText("0");
    symbol = false;
    deadScan = false;
}


