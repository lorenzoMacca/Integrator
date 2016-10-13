#include "qjira.h"
#include <QVariant>


QJira::QJira(QObject *parent)
	: QObject(parent)
{

}

QJira::~QJira()
{

}

QStandardItemModel* QJira::getModelData(const QString *project, QString *issue_type)
{
	QList<Ticket*> tickets = this->getTicketsTest();
	QStandardItemModel* model = new QStandardItemModel(this);

	int tableIndex = 0;
	for(int i=0; i<tickets.size(); i++){
		if(i==0){
			model->setHorizontalHeaderItem(0, new QStandardItem("Key"));
			model->setHorizontalHeaderItem(1, new QStandardItem("Summary"));
			model->setHorizontalHeaderItem(2, new QStandardItem("Security level"));
			model->setHorizontalHeaderItem(3, new QStandardItem("Sub project"));
			model->setHorizontalHeaderItem(4, new QStandardItem("Subproject Rel"));
		}
		ErrTicket* errTicket = (ErrTicket*)tickets.at(i);
		bool isRelated = false;
		if(errTicket->getSubProject().compare(*project) == 0){//check sub project
			isRelated = true;
		}else{//check subproject relations
			QStringList list = errTicket->getSubProjectRelations().split(",", QString::SkipEmptyParts); 
			for(int j=0; j<list.size(); j++){
				if(list.at(j).compare(*project) == 0){
					isRelated = true;
					break;
				}
			}
		}
		if(isRelated){
			QStandardItem *i1 = new QStandardItem(QString(errTicket->getKey()));
			QStandardItem *i2 = new QStandardItem(QString(errTicket->getSummary()));
			QStandardItem *i3 = new QStandardItem(QString(errTicket->getSecurityLevel()));
			QStandardItem *i4 = new QStandardItem(QString(errTicket->getSubProject()));
			QStandardItem *i5 = new QStandardItem(QString(errTicket->getSubProjectRelations()));
			model->setItem(tableIndex, 0, i1);
			model->setItem(tableIndex, 1, i2);
			model->setItem(tableIndex, 2, i3);
			model->setItem(tableIndex, 3, i4);
			model->setItem(tableIndex, 4, i5);
			tableIndex++;
		}
	}
	return model;
}

QList<Ticket*> QJira::getTicketsTest()
{
	QList<Ticket*> ticketsFromJira;

	ErrTicket *tmp1 = new ErrTicket("GL005-001122", "[Compiler warning] - N°1 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"HON02", "HON02,CRY01,COR01",	"2275",	"2271",	this);	
	ErrTicket *tmp2 = new ErrTicket("GL005-001174", "[Compiler warning] - N°2 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"HON02", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp3 = new ErrTicket("GL005-001124", "[Compiler warning] - N°3 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"CRY01", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp4 = new ErrTicket("GL005-001125", "[Compiler warning] - N°4 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"COR01", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp5 = new ErrTicket("GL005-001126", "[Compiler warning] - N°5 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"HON02", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp6 = new ErrTicket("GL005-001127", "[Compiler warning] - N°6 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"HON02", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp7 = new ErrTicket("GL005-001128", "[Compiler warning] - N°7 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"HON02", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp8 = new ErrTicket("GL005-001129", "[Compiler warning] - N°8 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"COR01", "HON02,CRY01,COR01",	"2275",	"2271",	this);	
	ErrTicket *tmp9 = new ErrTicket("GL005-001110", "[Compiler warning] - N°9 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe",	"2016-05-30", "schetler.denis", "lalalala", "AMFM",	"CRY01", "HON02,CRY01",	"2275",	"2271",	this);	
	ErrTicket *tmp10 = new ErrTicket("GL005-001131", "[Compiler warning] - N°10 deviation in AMFM_059.001.003", "gl005_onsite", "Bruno, Giuseppe","2016-05-30", "schetler.denis", "lalalala", "AMFM",	"CRY01", "HON02,CRY01",	"2275",	"2271",	this);	
	
	ticketsFromJira.append(tmp1);
	ticketsFromJira.append(tmp2);
	ticketsFromJira.append(tmp3);
	ticketsFromJira.append(tmp4);
	ticketsFromJira.append(tmp5);
	ticketsFromJira.append(tmp6);
	ticketsFromJira.append(tmp7);
	ticketsFromJira.append(tmp8);
	ticketsFromJira.append(tmp9);
	ticketsFromJira.append(tmp10);

	return ticketsFromJira;
}
