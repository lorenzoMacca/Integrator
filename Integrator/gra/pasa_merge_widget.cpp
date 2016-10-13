#include "pasa_merge_widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QMessageBox>

PasaMergeWidget::PasaMergeWidget(QWidget *parent)
	: QWidget(parent)
{
	this->mergeProcess = new PaseMergeFod01(this);

	this->setMinimumHeight(400);
	this->setMaximumHeight(600);

	//create the layout_1
	QVBoxLayout *layout_1 = new QVBoxLayout;

	paseProjectQLE = new QLineEdit;
	paseProjectQLE->setPlaceholderText("Insert the path of the PASE working copy");
	browsePaseFolder = new QPushButton("browse");
	QLabel *paseQL = new QLabel("Pase working copy");
	pasaProjectQLE = new QLineEdit;
	pasaProjectQLE->setPlaceholderText("Insert the path of the PASA working copy");
	browsePasaFolder = new QPushButton("browse");
	QLabel *pasaQL = new QLabel("Pasa working copy");
	outputProcessQTE = new QTextEdit(this);
	outputProcessQTE->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding); 

	//create the layout_2
	QHBoxLayout *layout_2 = new QHBoxLayout;

	//you wanna use the QSpacerItem but QHBoxLayout alredy provide some 
	//method to manage the empta space, see http://doc.qt.io/qt-4.8/qspaceritem.html
	//QSpacerItem* horizontalSpacer = new QSpacerItem(250, 20);

	this->runQB = new QPushButton(this);
	runQB->setText(tr("Run script"));
	runQB->setMinimumSize(150, 50);
	runQB->setMaximumSize(160, 50);
	

	QPushButton* backQB = new QPushButton(this);
	backQB->setText(tr("go back"));
	backQB->setMinimumSize(150, 50);
	backQB->setMaximumSize(160, 50);

	// Set layout
	//layout->addSpacerItem(horizontalSpacer);
	layout_2->addWidget(backQB);
	layout_2->addWidget(runQB);
	layout_2->insertStretch(0, 0);
	
	QHBoxLayout *layout_1_1 = new QHBoxLayout;
	layout_1_1->addWidget(paseProjectQLE);
	layout_1_1->addWidget(browsePaseFolder);
	layout_1->addWidget(paseQL);
	layout_1->addItem(layout_1_1);

	QHBoxLayout *layout_1_2 = new QHBoxLayout;
	layout_1_2->addWidget(pasaProjectQLE);
	layout_1_2->addWidget(browsePasaFolder);
	layout_1->addWidget(pasaQL);
	layout_1->addItem(layout_1_2);

	layout_1->addItem(layout_2);
	layout_1->addWidget(outputProcessQTE);
	layout_1->insertStretch(-1, 0);
	this->setLayout(layout_1);

	connect(this->runQB,SIGNAL (released()),
		    this, SLOT(runScript()));
	connect(this->paseProjectQLE, SIGNAL(textEdited(const QString&)),
		    this, SLOT(handleTextChangedPasePath(const QString&)));
	connect(this->pasaProjectQLE, SIGNAL(textEdited(const QString&)),
		    this, SLOT(handleTextChangedPasaPath(const QString&)));
	connect(this->browsePaseFolder,SIGNAL (released()),
		    this, SLOT(handleBrowsePaseFolderButton()));
	connect(this->browsePasaFolder,SIGNAL (released()),
		    this, SLOT(handleBrowsePasaFolderButton()));

	connect(this->mergeProcess,SIGNAL (mergeStarted()),
		    this, SLOT(handleMergeStarted()));
	connect(this->mergeProcess,SIGNAL (mergeFinished()),
		    this, SLOT(handleMergeFinished()));

	connect(this->mergeProcess,SIGNAL (mergeError(int , QString )),
		    this, SLOT(handleMergeError(int , QString )));

	connect(this->mergeProcess,SIGNAL (readStandardInput(QString )),
		    this, SLOT(handleOutputProcess(QString )));
}

PasaMergeWidget::~PasaMergeWidget()
{

}

void PasaMergeWidget::runScript(){
	//QMessageBox::StandardButton reply = QMessageBox::information(this, "Info", "Script is running");
	this->mergeProcess->run();
}

void PasaMergeWidget::handleTextChangedPasePath(const QString & text)
{
	this->mergeProcess->setpaseProjectPath(text);
}

void PasaMergeWidget::handleTextChangedPasaPath(const QString & text)
{
	this->mergeProcess->setpasaProjectPath(text);
}

void PasaMergeWidget::handleBrowsePaseFolderButton()
{
	QString tmpDir = QFileDialog::getExistingDirectory(this,
	tr("Select the Pase working copy"),
	*this->preferredRootFolder(),
	QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	this->paseProjectQLE->setText(tmpDir); //this won't trigger any signals
	this->mergeProcess->setpaseProjectPath(tmpDir);
}

void PasaMergeWidget::handleBrowsePasaFolderButton()
{
	QString tmpDir = QFileDialog::getExistingDirectory(this,
	tr("Select the Pasa working copy"),
	*this->preferredRootFolder(),
	QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	this->pasaProjectQLE->setText(tmpDir); //this won't trigger any signals
	this->mergeProcess->setpasaProjectPath(tmpDir);
	
}

QString* PasaMergeWidget::preferredRootFolder() const
{
	QString* tmp = new QString("D:/Users/extern.lorenzo/Documents/GL005");
	return tmp;
}

void PasaMergeWidget::handleMergeStarted()
{
	this->runQB->setEnabled(false);
}

void PasaMergeWidget::handleMergeFinished()
{
	this->runQB->setEnabled(true);
}

void PasaMergeWidget::handleMergeError(int code, QString description)
{
	switch(code){
		case(PaseMergeFod01::PASE_FOLDER_NOT_FOUND):
			qDebug() << description;
			QMessageBox::critical(this, "Pase folder not found", description);
			break;
		case(PaseMergeFod01::PASA_FOLDER_NOT_FOUND):
			QMessageBox::critical(this, "Pasa folder not found", description);
			qDebug() << description;
			break;
		case(PaseMergeFod01::NO_HEADER_FILE_FOUND_IN_RTC):
			QMessageBox::critical(this, "header file not found in RTC", "please check the RTC working copy, It seems that does not contein the header files");
			qDebug() << description;
			break;
		default:
			break;
	}

}

void PasaMergeWidget::handleOutputProcess(QString text)
{
	this->outputProcessQTE->append(text);
}