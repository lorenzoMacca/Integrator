#include "definebuildwidget.h"
#include "ui_definebuildwidget.h"

DefineBuildWidget::DefineBuildWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefineBuildWidget)
{
    ui->setupUi(this);
    /*if( build == 0 ) return;
    this->m_build = build;*/

}

DefineBuildWidget::~DefineBuildWidget()
{
    delete ui;
}
