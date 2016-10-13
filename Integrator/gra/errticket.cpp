#include "errticket.h"

ErrTicket::ErrTicket(QString key, QString summary, QString securityLevel, QString assignee, QString due_date, QString pic, QString description, QString component, 
					 QString sub_project, QString sub_project_relations, QString next_build_revision, QString commit_revision,
					 QObject *parent)
	: Ticket(key, summary, securityLevel, assignee, due_date, pic, description, component, parent)
{
	this->sub_project=sub_project;
	this->sub_project_relations=sub_project_relations;
	this->next_build_revision=next_build_revision;
	this->commit_revision=commit_revision;
}

ErrTicket::~ErrTicket()
{

}

QString ErrTicket::getSubProject()
{
	return this->sub_project;
}

QString ErrTicket::getSubProjectRelations()
{
	return this->sub_project_relations;
}

QString ErrTicket::getNextBuildRevision()
{
	return this->next_build_revision;
}

QString ErrTicket::getCommitRevision()
{
	return this->commit_revision;
}
