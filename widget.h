#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void btn_logic(int x,QString y=" ");
    void den_logic();
public:
    QString a;//存储lineEdit的内容
    QStringList b;//用来存储运算符
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
