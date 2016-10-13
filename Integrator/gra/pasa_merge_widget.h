#ifndef PasaMergeWidget_H
#define PasaMergeWidget_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "pasemergefod01.h"
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QTextEdit>

class PasaMergeWidget : public QWidget
{
	Q_OBJECT

public:
	PasaMergeWidget(QWidget *parent);
	~PasaMergeWidget();

private slots:
	void runScript();
	void handleTextChangedPasePath(const QString & text);
	void handleTextChangedPasaPath(const QString & text);
	void handleBrowsePaseFolderButton();
	void handleBrowsePasaFolderButton();
	void handleMergeStarted();
	void handleOutputProcess(QString text);
	void handleMergeFinished();
	void handleMergeError(int code, QString description);

private:
	QPushButton* runQB;
	QLineEdit *paseProjectQLE;
	QPushButton* browsePaseFolder;
	QLineEdit *pasaProjectQLE;
	QPushButton* browsePasaFolder;
	PaseMergeFod01 *mergeProcess;
	QString* preferredRootFolder() const;
	QTextEdit *outputProcessQTE;
	
};

#endif // PasaMergeWidget_H
