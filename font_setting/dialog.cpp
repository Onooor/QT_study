#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->blackbtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(ui->bluebtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(ui->redbtn, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_cbox1_clicked(bool checked)
{
    QFont font=ui->TextEdit->font();
    font.setUnderline(checked);
    ui->TextEdit->setFont(font);
}


void Dialog::on_cbox2_clicked(bool checked)
{
    QFont font=ui->TextEdit->font();
    font.setItalic(checked);
    ui->TextEdit->setFont(font);
}


void Dialog::on_cbox3_clicked(bool checked)
{
    QFont font=ui->TextEdit->font();
    font.setBold(checked);
    ui->TextEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet=ui->TextEdit->palette();
    if(ui->blackbtn->isChecked()){
        plet.setColor(QPalette::Text,Qt::black);
    }else if(ui->bluebtn->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue);
    }else if(ui->redbtn->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }
    ui->TextEdit->setPalette(plet);
}

