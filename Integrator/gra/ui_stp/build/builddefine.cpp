#include "builddefine.h"
#include "ui_builddefine.h"

BuildDefine::BuildDefine(Data *d, int buildNumber, IntegrationPlan *i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildDefine)
{
    ui->setupUi(this);
    this->m_i = i;
    this->m_buildNumber = buildNumber;

    for(int i=0; i<this->ui->tabWidget->count(); i++)
    {
        this->ui->tabWidget->removeTab(i);
    }

    for( int i=0; i<this->m_buildNumber; i++ )
    {
        this->ui->tabWidget->addTab(new DefineBuildWidget(d, this->ui->tabWidget), "BUILD_"+QString::number(i));
    }


}

BuildDefine::~BuildDefine()
{
    delete ui;
}
