#ifndef UIJIRASTPINTERFACE_H
#define UIJIRASTPINTERFACE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QFont>
#include <QDebug>
#include "src/core/data/data.h"
#include "src/core/jiraConnection/CreateJiraSPTInputFileCsv.h"
#include "src/core/jiraConnection/JiraSPInputFileCsv.h"
#include "src/core/jiraConnection/JiraScriptExecutor.h"
#include "src/core/jiraConnection/DefaultjiraScriptExecutor.h"
#include "ui_uijirastpinterface.h"

class UIJiraStpInterface : public QMainWindow
{
	Q_OBJECT

public:
    UIJiraStpInterface(Data *d = 0, QWidget *parent = 0);
	~UIJiraStpInterface();

public slots:
	void handleCloseButton();
	void handleJiraTicketButton();
	void handlePrintHtmlCodeButton();
	void handleStartedSTPCreation();
	void handleFinischedSTPCreation();
	void handleIntegrationPlanNotVerified();
    void handleOutputProcess();

private:
	Ui::UIJiraStpInterfaceClass ui;
	Data *m_data;

	QPushButton *m_close_window_button;
	QPushButton *m_print_HTML_code_button;
	QPushButton *m_create_jira_ticket_button;
	QTextEdit *m_output_text_from_jira;
	QString m_html_out;
	JiraScriptExecutor *m_jira_script_ececutor;

	bool checkInputData();

	void connects();
};

#endif // UIJIRASTPINTERFACE_H
