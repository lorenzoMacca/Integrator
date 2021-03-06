#include "builddefine.h"
#include "ui_builddefine.h"

BuildDefine::BuildDefine(Data *data, int buildNumber, IntegrationPlan *i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuildDefine)
{
    ui->setupUi(this);
    this->m_i = i;
    this->m_buildNumber = buildNumber;


    //qDebug() << "numebr of tabs" << QString::number(this->ui->tabWidget->count());

    for( int i=0; i<this->m_buildNumber; i++ )
    {
        Build b(data->integrationPlan());
        QString build_name = "BUILD_"+QString::number(i);
        b.setName(build_name);
        data->integrationPlan()->addBuild(b);
        DefineBuildWidget *d = new DefineBuildWidget(i, data, this->ui->tabWidget);
        this->ui->tabWidget->addTab(d, build_name);
        connect(d, SIGNAL(buildNameChanged(int, QString)), this, SLOT(handlBuildNameChange(int, QString)));
    }

    /*removing the defauld tabs*/
    this->ui->tabWidget->removeTab(0);
    this->ui->tabWidget->removeTab(0);

    connect(this->ui->m_back_button, SIGNAL(released()), this, SLOT(handleBackButtonPressed()));
    connect(this->ui->m_next_button, SIGNAL(released()), this, SLOT(handleNextButtonPressed()));
}

BuildDefine::~BuildDefine()
{
    delete ui;
}

void BuildDefine::handleBackButtonPressed()
{
    emit backButtonPressed();
}

void BuildDefine::handleNextButtonPressed()
{
    emit nextButtonPressed();
}

void BuildDefine::handlBuildNameChange(int index, QString n)
{
    if( n == "" )
    {
        n = "Build_" + QString::number(index);
    }
    this->ui->tabWidget->setTabText(index,n);
}
