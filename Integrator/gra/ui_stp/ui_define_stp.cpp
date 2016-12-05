#include "ui_define_stp.h"
#include "ui_ui_define_stp.h"

UIDefineSTP::UIDefineSTP(Data *d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->m_data = d;

    IntegrationPlan* i = this->m_data->integrationPlan();

    this->ui->m_ui_cw_2->setText(i->cw());
    this->ui->m_ui_start_date->setDate(i->start_date());
    this->ui->m_ui_due_date->setDate(i->due_date());
    this->ui->m_ui_merge_date->setDate(i->merge_date());

    this->ui->m_isMerge->setChecked(!i->noMerge());
    if(i->noMerge())
    {
        this->ui->m_ui_merge_date->setDisabled(true);
    }else
    {
        this->ui->m_ui_merge_date->setDisabled(false);
    }

    this->ui->m_ui_sub_project->addItems(this->m_data->settingData()->subProjects());
    this->ui->m_ui_assignee->addItems(this->m_data->settingData()->assignees());
    this->ui->m_ui_pic->addItems(this->m_data->settingData()->pics());
    this->ui->m_ui_buildtype->addItems(this->m_data->settingData()->stp_types());
	this->ui->m_ui_security_level->addItems(this->m_data->settingData()->securityLevels());

    int i1 = this->ui->m_ui_sub_project->findText(i->sub_project());
    if(i1 > -1)
    {
        this->ui->m_ui_sub_project->setCurrentIndex(i1);
    }

    int i2 = this->ui->m_ui_assignee->findText(i->assignees());
    if(i2 > -1)
    {
        this->ui->m_ui_assignee->setCurrentIndex(i2);
    }

    int i3 = this->ui->m_ui_pic->findText(i->assignees());
    if(i3 > -1)
    {
        this->ui->m_ui_pic->setCurrentIndex(i3);
    }

    int i4 = this->ui->m_ui_buildtype->findText(i->stp_type());
    if(i4 > -1)
    {
        this->ui->m_ui_buildtype->setCurrentIndex(i4);
    }

    int i5 = this->ui->m_ui_security_level->findText(i->security_level());
    if(i5 > -1)
    {
        this->ui->m_ui_security_level->setCurrentIndex(i5);
    }


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
		QString summary = "SP ticket for " + this->m_data->integrationPlan()->sub_project() + " release CW";
		this->m_data->integrationPlan()->setSummary(summary);

        emit integrationPlanInitializedAfterCallToNextButton();
    }
}

void UIDefineSTP::next()
{
    if( this->ui->m_ui_num_build->text().toInt() > 0 )
    {
        QMessageBox::information(this, "STP definition", "STP correctly configured");
        emit nextButtonPressed(this->ui->m_ui_num_build->text().toInt());
    }

    //qDebug() << this->m_data->integrationPlan()->toString();

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


