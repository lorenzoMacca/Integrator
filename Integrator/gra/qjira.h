#ifndef QJIRA_H
#define QJIRA_H

#include <QObject>
#include "errticket.h"
#include <QStandardItemModel>
#include <QList>
#include <QDebug>
#include <QStringList>

class QJira : public QObject
{
	Q_OBJECT

public:
	QJira(QObject *parent);
	~QJira();
	QStandardItemModel* getModelData(const QString *project, QString *issue_type);


private:
	QList<Ticket*> getTicketsTest();
};

#endif // QJIRA_H
