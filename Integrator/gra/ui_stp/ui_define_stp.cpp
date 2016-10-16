#include "ui_define_stp.h"
#include "ui_ui_define_stp.h"

UIDefineSTP::UIDefineSTP(Data *d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->m_data = d;

    this->ui->m_ui_cw_2->setText(QString::number(QDate::currentDate().weekNumber()));
    this->ui->m_ui_sub_project->addItems(this->m_data->settingData()->subProjects());
    this->ui->m_ui_assignee->addItems(this->m_data->settingData()->assignees());
    this->ui->m_ui_pic->addItems(this->m_data->settingData()->pics());
    this->ui->m_ui_buildtype->addItems(this->m_data->settingData()->stp_types());
    this->ui->m_ui_start_date->setDate(QDate::currentDate());
    this->ui->m_ui_due_date->setDate(QDate::currentDate());
    this->ui->m_ui_merge_date->setDate(QDate::currentDate());
}

UIDefineSTP::~UIDefineSTP()
{
    delete ui;
}
