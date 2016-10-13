#ifndef TICKET_H
#define TICKET_H

#include <QObject>
#include <QString>
#include <QStringList>

class Ticket : public QObject
{
	Q_OBJECT

public:
	Ticket(QString& key, QString& summary, QString& securityLevel, QString& assignee, QString& due_date, QString& pic, QString& description, QString& component, QObject *parent);
	~Ticket();
	QString getKey();
	QString getSummary();
	QString getSecurityLevel();
	QString getAssignee();
	QString getDueDate();
	QString getPic();
	QString getDescription();
	QString getComponent();
	static QStringList getProjectsList();

protected:
	QString key;
	QString summary;
	QString securityLevel;
	QString assignee;
	QString due_date;
	QString pic;
	QString description;
	QString component;

};

#endif // TICKET_H
