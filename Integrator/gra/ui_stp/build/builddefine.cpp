#include "builddefine.h"
#include "ui_builddefine.h"

BuildDefine::BuildDefine(Data *d, int buildNumber, IntegrationPlan *i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildDefine)
{
    ui->setupUi(this);
    this->m_i = i;
    this->m_buildNumber = buildNumber;


    //qDebug() << "numebr of tabs" << QString::number(this->ui->tabWidget->count());

    for( int i=0; i<this->m_buildNumber; i++ )
    {
        this->ui->tabWidget->addTab(new DefineBuildWidget(d, this->ui->tabWidget), "BUILD_"+QString::number(i));
    }

    /*removing the defauld tabs*/
    this->ui->tabWidget->removeTab(0);
    this->ui->tabWidget->removeTab(0);
}

BuildDefine::~BuildDefine()
{
    delete ui;
}
