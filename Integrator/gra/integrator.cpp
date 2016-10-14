#include "integrator.h"

Integrator::Integrator(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	this->w = 0;
	QVBoxLayout *layout = new QVBoxLayout;
	this->ui.widget->setLayout(layout);

	//TO_TEST
    //this->w = new JiraTickets(this);
    //this->ui.widget->layout()->addWidget(this->w);
    this->w = new UIDefineSTP(this);
    this->ui.widget->layout()->addWidget(this->w);
	//TO_TEST

	connect(this->ui.actionMerge, SIGNAL(triggered()), this, SLOT(handleMergeAction()));
	connect(this->ui.actionDeadline, SIGNAL(triggered()), this, SLOT(handleHomePageAction()));
}

Integrator::~Integrator()
{

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
