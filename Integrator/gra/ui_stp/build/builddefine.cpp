#include "builddefine.h"
#include "ui_builddefine.h"

BuildDefine::BuildDefine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildDefine)
{
    ui->setupUi(this);
    this->ui->tabWidget->removeTab(0);
    //this->ui->tabWidget->removeTab(1);
    this->ui->tabWidget->addTab(new DefineBuildWidget(this->ui->tabWidget), "BUILD0");
}

BuildDefine::~BuildDefine()
{
    delete ui;
}
