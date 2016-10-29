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
	this->ui->m_ui_security_level->addItems(this->m_data->settingData()->securityLevels());
    this->ui->m_ui_merge_date->setDisabled(false);
    this->ui->m_isMerge->setChecked(true);
	

    connect(this->ui->m_next_button, SIGNAL(clicked()),
            this, SLOT(nextButtonClicketSlot()));
    connect(this, SIGNAL(integrationPlanInitializedAfterCallToNextButton()),
            this, SLOT(next()));
    connect(this->ui->m_isMerge, SIGNAL(stateChanged(int)),
            this, SLOT(handleIsMergeCheckBox(int)));
}

UIDefineSTP::~UIDefineSTP()
{
    delete ui;
}

void UIDefineSTP::nextButtonClicketSlot()
{
    //save info stp
    if(this->m_data->integrationPlan() != NULL)
    {
        this->m_data->integrationPlan()->setCw(this->ui->m_ui_cw_2->text());
        this->m_data->integrationPlan()->setStartDate(this->ui->m_ui_start_date->date());
        this->m_data->integrationPlan()->setDueDate(this->ui->m_ui_due_date->date());
        this->m_data->integrationPlan()->setMergeDate(this->ui->m_ui_merge_date->date());
        this->m_data->integrationPlan()->setNoMerge(!this->ui->m_isMerge->isChecked());
        this->m_data->integrationPlan()->setSubProject(this->ui->m_ui_sub_project->currentText());
        this->m_data->integrationPlan()->setAssignees(this->ui->m_ui_assignee->currentText());
        this->m_data->integrationPlan()->setPic(this->ui->m_ui_pic->currentText());
        this->m_data->integrationPlan()->setStpType(this->ui->m_ui_buildtype->currentText());
		this->m_data->integrationPlan()->setSecurityLevel(this->ui->m_ui_security_level->currentText());
        emit integrationPlanInitializedAfterCallToNextButton();
    }
}

void UIDefineSTP::next()
{
    QMessageBox::information(this, "Next Button clicked", "The button was clicked");
    qDebug() << this->m_data->integrationPlan()->toString();
    emit nextButtonPressed(this->ui->m_ui_num_build->text().toInt());
}

void UIDefineSTP::handleIsMergeCheckBox(int state)
{
    if( state == Qt::Checked )
    {
        this->ui->m_ui_merge_date->setDisabled(false);
    }else if( state == Qt::Unchecked )
    {
        this->ui->m_ui_merge_date->setDisabled(true);
    }
}


