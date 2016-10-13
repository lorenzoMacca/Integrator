#ifndef ERRTICKET_H
#define ERRTICKET_H

#include <QObject>
#include "ticket.h"

class ErrTicket : public Ticket
{
public:
	ErrTicket(QString key, QString summary, QString securityLevel, QString assignee, QString due_date, QString pic, QString description, QString component, 
		QString sub_project, QString sub_project_relations, QString next_build_revision, QString commit_revision,
		QObject *parent);
	~ErrTicket();
	QString getSubProject();
	QString getSubProjectRelations();
	QString getNextBuildRevision();
	QString getCommitRevision();

private:
	QString sub_project;
	QString sub_project_relations;
	QString next_build_revision;
	QString commit_revision;
};

#endif // ERRTICKET_H
