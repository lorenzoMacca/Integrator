#include "test_qmv_01.h"
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QSplitter>
#include <QTableView>


Test_QMV_01::Test_QMV_01(QWidget *parent)
	: QWidget(parent)
{

	QSplitter *splitter = new QSplitter(Qt::Horizontal,this);

	QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
	QTreeView *tree = new QTreeView(this);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
	QListView *list = new QListView(this);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

	QTableView *table = new QTableView();
	QJira *jire_tmp = new QJira(this);
	table->setModel( jire_tmp->getModelData(new QString(""), new QString("")) );
	table->setSortingEnabled(true);

	QVBoxLayout *layout_1 = new QVBoxLayout;
	QLabel *testQL = new QLabel("Test Qt label");
	splitter->addWidget(tree);
	splitter->addWidget(list);
	splitter->addWidget(table);
	layout_1->addWidget(splitter);
	//layout_1->addWidget(testQL);
	//layout_1->addWidget(tree);
	//layout_1->addWidget(list);
	this->setLayout(layout_1);

	connect(table, SIGNAL(clicked(const QModelIndex & )),
		    this, SLOT(handleMouseClickedEvent(const QModelIndex & )));
}

Test_QMV_01::~Test_QMV_01()
{

}

QStandardItemModel* Test_QMV_01::getTestModelO1()
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

void Test_QMV_01::handleMouseClickedEvent(const QModelIndex & index)
{
	qDebug() << "mouse clicked" << index.data().toString();
}
