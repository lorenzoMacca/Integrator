#include "ui_define_stp.h"
#include "ui_ui_define_stp.h"

UIDefineSTP::UIDefineSTP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

UIDefineSTP::~UIDefineSTP()
{
    delete ui;
}
