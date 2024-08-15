#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->commandLineEdit, &QLineEdit::returnPressed, this, &Widget::on_commitButton_clicked);
    //connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(on_cancelButton_clicked()));
    connect(ui->browseButton, &QPushButton::clicked,
    [this](){
        QMessageBox::information(this,"infro","clickbrowse");
    }
    );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_commitButton_clicked()
{
    QString program =ui->commandLineEdit->text();
    QProcess* myProcess = new QProcess(this);
    myProcess->start(program);
}


void Widget::on_cancelButton_clicked()
{
    this->close();
}



