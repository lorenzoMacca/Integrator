#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <QMainWindow>
#include <QWidget>
#include "ui_integrator.h"
#include <QPushButton>
#include "mainintegratorwidget.h"
#include "pasa_merge_widget.h"
#include "test_qmv_01.h"
#include "jiratickets.h"
#include "gra/ui_stp/ui_define_stp.h"

class Integrator : public QMainWindow
{
	Q_OBJECT

public:
    Integrator(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~Integrator();

public slots:
	void handleMergeAction();
	void handleHomePageAction();

private:
	Ui::IntegratorClass ui;
	QWidget* w;
};

#endif // INTEGRATOR_H
