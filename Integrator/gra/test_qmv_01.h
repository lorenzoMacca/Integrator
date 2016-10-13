#ifndef TEST_QMV_01_H
#define TEST_QMV_01_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QDebug>
#include "qjira.h"

class Test_QMV_01 : public QWidget
{
	Q_OBJECT

public:
	Test_QMV_01(QWidget *parent);
	~Test_QMV_01();
	
public slots:
	void handleMouseClickedEvent(const QModelIndex & index);

private:
	QStandardItemModel* getTestModelO1();
};

#endif // TEST_QMV_01_H
