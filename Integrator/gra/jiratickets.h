#ifndef JIRATICKETS_H
#define JIRATICKETS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QDebug>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QSplitter>
#include <QTableView>
#include <QTabWidget>
#include "qjira.h"


class JiraTickets : public QWidget
{
	Q_OBJECT

public:
	JiraTickets(QWidget *parent);
	~JiraTickets();

public slots:
	void handleMouseClickedEvent(const QModelIndex & index);

private:
	QStandardItemModel* getTestModelO1();
};

#endif // JIRATICKETS_H
