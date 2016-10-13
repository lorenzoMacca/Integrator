#include "jiratickets.h"

JiraTickets::JiraTickets(QWidget *parent)
	: QWidget(parent)
{
	QTabWidget *tabs = new QTabWidget(this);
	tabs->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	QStringList projectsList = Ticket::getProjectsList();
	QJira *jire_tmp = new QJira(this);
	tabs->setMinimumSize(700, 450);

	for(int i=0; i<projectsList.size(); i++){
		QTableView *table = new QTableView();
		table->setModel( jire_tmp->getModelData(&projectsList.at(i), new QString("ERR")) );
		table->setSortingEnabled(true);
		tabs->addTab(table, projectsList.at(i));
	}

	/*connect(tableCOR01, SIGNAL(clicked(const QModelIndex & )),
		    this, SLOT(handleMouseClickedEvent(const QModelIndex & )));*/
}

JiraTickets::~JiraTickets()
{

}

QStandardItemModel* JiraTickets::getTestModelO1()
{
	QStandardItemModel *model = new QStandardItemModel( 5, 2 );
	for( int r=0; r<5; r++ ) 
		for( int c=0; c<2; c++) 
		{
			QStandardItem *item = new QStandardItem( QString("Row:%0, Column:%1").arg(r).arg(c) );
      
			  if( c == 0 )
				for( int i=0; i<3; i++ ) 
					item->appendRow( new QStandardItem( QString("Item %0").arg(i) ) );
      
			model->setItem(r, c, item);
		}
	return model;
}

void JiraTickets::handleMouseClickedEvent(const QModelIndex & index)
{
	qDebug() << "mouse clicked" << index.data().toString();
}