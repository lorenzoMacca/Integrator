#include "ticket.h"

Ticket::Ticket(QString& key, QString& summary, QString& securityLevel, QString& assignee, QString& due_date, QString& pic, QString& description, QString& component, QObject *parent)
	: QObject(parent)
{
	this->key=key;
	this->summary=summary;
	this->securityLevel=securityLevel;
	this->assignee=assignee;
	this->due_date=due_date;
	this->pic=pic;
	this->description=description;
	this->component=component;
}

Ticket::~Ticket()
{

}

QString Ticket::getSummary()
{
	return this->summary;
}

QString Ticket::getSecurityLevel()
{
	return this->securityLevel;
}

QString Ticket::getKey()
{
	return this->key;
}

QString Ticket::getAssignee()
{
	return this->assignee;
}

QString Ticket::getDueDate()
{
	return this->due_date;
}

QString Ticket::getPic()
{
	return this->pic;
}

QString Ticket::getDescription()
{
	return this->description;
}

QString Ticket::getComponent()
{
	return this->component;
}

QStringList Ticket::getProjectsList()
{
	QStringList list;
	list << "COR01" << "COR03" << "CRY01" << "FOD01" << "FOD03" << "HO16RT" << "HON02" << "HON03" << "PAE03" << "PAE04" << "SUZ01" << "SVT01" << "TOY01" << "VWA01" << "VWA02";
	return list;
}