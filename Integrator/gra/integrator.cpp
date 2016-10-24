#include "integrator.h"

Integrator::Integrator(Data *d, QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	this->w = 0;
	QVBoxLayout *layout = new QVBoxLayout;
	this->ui.widget->setLayout(layout);

	//TO_TEST
    //this->w = new JiraTickets(this);
    //this->ui.widget->layout()->addWidget(this->w);
	this->m_data = d;
   // this->w = new UIDefineSTP(d, this);
    this->m_data->integrationPlan()->setStartDate(QDate(2016,10,24));
    this->m_data->integrationPlan()->setDueDate(QDate(2016,10,28));
    this->w = new BuildDefine(this->m_data, 4, this->m_data->integrationPlan(), this);
    this->ui.widget->layout()->addWidget(this->w);
    //TO_TEST

	connect(this->ui.actionMerge, SIGNAL(triggered()), this, SLOT(handleMergeAction()));
	connect(this->ui.actionDeadline, SIGNAL(triggered()), this, SLOT(handleHomePageAction()));
	connect(this->ui.actionSTP_Creator, SIGNAL(triggered()), this, SLOT(handleSTPCreatorAction()));
}

Integrator::~Integrator()
{

}

void Integrator::handleSTPCreatorAction()
{
	this->handleHomePageAction();
	this->w = new UIDefineSTP(this->m_data, this);
	this->ui.widget->layout()->addWidget(this->w);
}

/**
* remove the current widgent and add the merge widget
* 
**/
void Integrator::handleMergeAction()
{
	this->handleHomePageAction();
	this->w = new PasaMergeWidget(this->ui.widget);
	this->ui.widget->layout()->addWidget(this->w);
}

void Integrator::handleHomePageAction()
{
	if(this->w != 0){
		this->w->hide();
		this->ui.widget->layout()->removeWidget(this->w);
		delete this->w;
		this->w = 0;
	}
}
