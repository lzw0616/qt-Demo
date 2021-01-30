#include "mainwindow.h"
#include "ui_mainwindow.h"
//导入头文件
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QTextCodec>
#include <QByteArray>
#define cout qDebug()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actiondakai_triggered()
{
    //打开文件
    /*1.fopen(文件名,打开方式)
     *2.判断可用性
     *3.读取内容
     *4.关闭
     *
     */
    QString fileName=QFileDialog::getOpenFileName();
//    cout<<"=="<<fileName<<"===";
    QTextCodec * codec=QTextCodec::codecForName("GBK");
//    char *file=codec->fromUnicode(fileName).data();
    QByteArray ba=fileName.toLatin1();
    char *file=ba.data();
    FILE *fp=fopen(file,"r");
    if(!fp)
        return;
    cout<<"文件打开成功"<<endl;
    char buf[1024];
    QString text;
    while(!feof(fp))
    {
        memset(buf,0,1024);
        fgets(buf,1024,fp);
        text+=codec->toUnicode(buf);

    }
     ui->textEdit->setText(text);
     fclose(fp);
}

void MainWindow::on_actionbaocun_triggered()
{
    //打开文件
    QString fileName=QFileDialog::getSaveFileName();
    //转码
    QTextCodec * codec=QTextCodec::codecForName("GBK");
    char * file=codec->fromUnicode(fileName).data();
    FILE * fp=fopen(file,"w");
    if(!fp)
        return;
    //读取textEdit
    QString text=ui->textEdit->toPlainText();
    const char * buf=text.toStdString().data();
    fputs(buf,fp);
    fclose(fp);
}

void MainWindow::on_actionxinjian_triggered()
{
//    ui->textEdit->setText("");
    ui->textEdit->clear();
}

void MainWindow::on_actiontuichu_triggered()
{
    exit(0);
}

void MainWindow::on_actionchexiao_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionfuzhi_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionzhantie_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionjianqie_triggered()
{
    ui->textEdit->cut();
}
