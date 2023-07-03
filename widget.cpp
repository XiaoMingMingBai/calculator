#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("李跃武版计算器");
    QPalette p=this->palette();
    p.setBrush(QPalette::Window,QColor(255,255,0));
    this->setPalette(p);
    a.clear();//清空
    b.clear();//清空
    //绑定0按钮
    connect(ui->pushButton0,&QPushButton::clicked,[=](){btn_logic(0);});
    //绑定1按钮
    connect(ui->pushButton1,&QPushButton::clicked,[=](){btn_logic(1);});
    //绑定2按钮
    connect(ui->pushButton2,&QPushButton::clicked,[=](){btn_logic(2);});
    //绑定3按钮
    connect(ui->pushButton3,&QPushButton::clicked,[=](){btn_logic(3);});
    //绑定4按钮
    connect(ui->pushButton4,&QPushButton::clicked,[=](){btn_logic(4);});
    //绑定5按钮
    connect(ui->pushButton5,&QPushButton::clicked,[=](){btn_logic(5);});
    //绑定6按钮
    connect(ui->pushButton6,&QPushButton::clicked,[=](){btn_logic(6);});
    //绑定7按钮
    connect(ui->pushButton7,&QPushButton::clicked,[=](){btn_logic(7);});
    //绑定8按钮
    connect(ui->pushButton8,&QPushButton::clicked,[=](){btn_logic(8);});
    //绑定9按钮
    connect(ui->pushButton9,&QPushButton::clicked,[=](){btn_logic(9);});
    //绑定加按钮
    connect(ui->pushButtonjia,&QPushButton::clicked,[=](){btn_logic(0,"+");});
    //绑定减按钮
    connect(ui->pushButtonjian,&QPushButton::clicked,[=](){btn_logic(0,"-");});
   //绑定乘按钮
    connect(ui->pushButtoncheng,&QPushButton::clicked,[=](){btn_logic(0,"*");});
   //绑定除按钮
    connect(ui->pushButtonchu,&QPushButton::clicked,[=](){btn_logic(0,"/");});
   //绑定等号按钮
    connect(ui->pushButtondengyu,&QPushButton::clicked,[=](){btn_logic(0,"=");});
   //绑定清空
    connect(ui->pushButtongui0,&QPushButton::clicked,[=](){
        a.clear();
        b.clear();
        //刷新lineEdit的内容
        ui->lineEdit->setText(a);

    });
    //绑定删除
    connect(ui->pushButtonqingchu,&QPushButton::clicked,[=](){
        a.chop(1);
        //刷新
        ui->lineEdit->setText(a);
    ;});
}

void Widget::btn_logic(int x, QString y)
{
  if(y==" "){
      a+=QString::number(x);
  }else if(x==0) {
      /*如果运算符的按钮按下以后
       * 将lineEdit中的内容写入到b【0】中
       */
      if(y!="="){
      b.insert(0,a);
      a.clear();
      b.insert(1,y);
    }else {
      b.insert(2,a);
      den_logic();
}

}

  //内容显示
   ui->lineEdit->setText(a);

}

void Widget::den_logic()
{
    a.clear();
    if(b.at(1)=="+"){
    a+=QString::number( QString(b.at(0)).toInt()+QString(b.at(2)).toUInt());
    }
    else if(b.at(1)=="-"){
        a+=QString::number( QString(b.at(0)).toInt()-QString(b.at(2)).toUInt());
    }
    else if(b.at(1)=="*"){
        a+=QString::number( QString(b.at(0)).toInt()*QString(b.at(2)).toUInt());
    }
    else if(b.at(1)=="/"){
        a+=QString::number( QString(b.at(0)).toInt()/QString(b.at(2)).toUInt());
    }
    ui->lineEdit->setText(a);
}
Widget::~Widget()
{
    delete ui;
}
