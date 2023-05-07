#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) // 这是MainWindow的构造函数，冒号后面就是调用了父类的构造函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // 这个就是对成员变量进行一个初始化，这条语句等价于ui = new Ui::MainWindow;
{
    ui->setupUi(this);
    // Qt的执行程序一般就是写在每个类的构造函数之中

    // 信号槽连接可以使用三种方法
    // 1. 使用connect(发送对象指针, SIGNAL(信号函数), 接收对象指针, SLOT(槽函数))函数
    // 2. 在ui界面的控件上点击右键，转到槽，然后编写槽函数
    // 3. 在ui界面的最下面使用qt工具选择添加槽(不常用)

    // 槽函数与信号函数的编写方法
    // 1. 信号函数声明时，需要使用关键字signals: 无返回值无参数的函数，只需写函数声明，不需要实现
    // 2. 槽函数声明时，需要使用关键字public slots: (限定是共有的槽函数)， 无返回值无参数的函数。需写函数声明，并且需要实现
    // 3. 自定义信号函数发送信号时，只用emit关键字，并且后面调用该函数。
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(printInfo()));
    connect(this, SIGNAL(send_msg()), this, SLOT(printInfo()));
    emit this->send_msg();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printInfo()
{
    qDebug() << "hello world" << endl;
}


void MainWindow::on_pushButton_2_clicked()
{
     qDebug() << "button2" << endl;
}
