#include "mainintegratorwidget.h"
#include <QPushButton>

MainIntegratorWidget::MainIntegratorWidget(QWidget *parent)
	: QWidget(parent)
{
	 QPushButton* pb = new QPushButton(this);
pb->move(100, 100);
pb->setText(tr("something"));
pb->setMinimumSize(100, 100);
pb->setMaximumSize(100, 100);
}

MainIntegratorWidget::~MainIntegratorWidget()
{

}
