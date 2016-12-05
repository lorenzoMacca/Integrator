#include "uijirastpinterface.h"

UIJiraStpInterface::UIJiraStpInterface(Data *d, QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	this->m_data = d;
	this->m_html_out = this->m_data->getHTMLCode();

	this->m_jira_script_ececutor = new DefaultJiraScriptExecutor(this->m_data, this);
	

	QString font_name("Consolas");

	/*
	*************************************************************
	** CENTRAL                                                 **
	*************************************************************
	*/
	QVBoxLayout *l1_v = new QVBoxLayout(this);
	QFont serifFontLabel(font_name, 12, QFont::Bold);
	QFont serifFontTextArea(font_name, 10);
	QLabel *text_area_label = new QLabel("Output from Jira scripts:", this);
	text_area_label->setFont(serifFontLabel);
	this->m_output_text_from_jira = new QTextEdit("output from jira scripts...", this);
	this->m_output_text_from_jira->setFont(serifFontTextArea);
	l1_v->addWidget(text_area_label);
	l1_v->addWidget(this->m_output_text_from_jira);

	QHBoxLayout *l2_h = new QHBoxLayout(this);
	this->m_close_window_button = new QPushButton("close", this);
	this->m_close_window_button->setMinimumSize(200, 50);
	QFont serifFont(font_name, 13, QFont::Bold);
	this->m_close_window_button->setFont(serifFont);
	this->m_create_jira_ticket_button = new QPushButton("Create jira ticket", this);
	this->m_create_jira_ticket_button->setMinimumSize(200, 50);
	this->m_create_jira_ticket_button->setFont(serifFont);
	this->m_print_HTML_code_button = new QPushButton("HTML code", this);
	this->m_print_HTML_code_button->setMinimumSize(200, 50);
	this->m_print_HTML_code_button->setFont(serifFont);

	//l2_h->addSpacing(500);
	l2_h->addStretch();
	l2_h->addWidget(this->m_close_window_button);
	l2_h->addWidget(this->m_print_HTML_code_button);
	l2_h->addWidget(this->m_create_jira_ticket_button);
	l1_v->addLayout(l2_h);

	this->ui.centralWidget->setLayout(l1_v);
	/*
	*************************************************************
	** END CENTRAL                                             **
	*************************************************************
	*/

	/*
	*************************************************************
	** FOOTER                                                  **
	*************************************************************
	*/
	QLabel *test_label = new QLabel("test", this);
	this->ui.statusBar->addWidget(test_label);
	/*
	*************************************************************
	** END FOOTER                                              **
	*************************************************************
	*/
	this->connects();

}

UIJiraStpInterface::~UIJiraStpInterface()
{

}

void UIJiraStpInterface::handleCloseButton()
{
	qDebug() << "handleCloseButton";
}

void UIJiraStpInterface::handleJiraTicketButton()
{
	qDebug() << "handleJiraTicketButton";
    bool result = this->m_jira_script_ececutor->createSPTicket();
	if(result)
	{
		qDebug() << "STP script ok";
	}
	else
	{
		qDebug() << "STP script NOK";
	}
	
}

void UIJiraStpInterface::handlePrintHtmlCodeButton()
{
	//qDebug() << "handlePrintHtmlCodeButton";
	this->m_output_text_from_jira->append(this->m_html_out);
}

void UIJiraStpInterface::connects()
{
	connect(this->m_close_window_button, SIGNAL(released()), this, SLOT(handleCloseButton()));
	connect(this->m_create_jira_ticket_button, SIGNAL(released()), this, SLOT(handleJiraTicketButton()));
	connect(this->m_print_HTML_code_button, SIGNAL(released()), this, SLOT(handlePrintHtmlCodeButton()));
	//jira
	connect(this->m_jira_script_ececutor, SIGNAL(started()), this, SLOT(handleStartedSTPCreation()));
	connect(this->m_jira_script_ececutor, SIGNAL(finished()), this, SLOT(handleFinischedSTPCreation()));
	connect(this->m_jira_script_ececutor, SIGNAL(integrationPlanNotVerified()), this, SLOT(handleIntegrationPlanNotVerified()));
}

bool UIJiraStpInterface::checkInputData()
{
	if( this->m_data == 0 )
	{
		return false;
	}
	
	return true;
}

void UIJiraStpInterface::handleStartedSTPCreation()
{
	qDebug() << "handleStartedSTPCreation";
}

void UIJiraStpInterface::handleFinischedSTPCreation()
{
	qDebug() << "handleFinischedSTPCreation";
}

void UIJiraStpInterface::handleIntegrationPlanNotVerified()
{
	qDebug() << "handleIntegrationPlanNotVerified";
}
