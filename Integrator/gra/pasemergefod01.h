#ifndef PASEMERGEFOD01_H
#define PASEMERGEFOD01_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QProcessEnvironment>
#include <QDir>

class PaseMergeFod01 : public QObject
{
	Q_OBJECT

public:
	PaseMergeFod01(QObject *parent);
	~PaseMergeFod01();
	void run();
	const static int PASE_FOLDER_NOT_FOUND = 1;
	const static int PASA_FOLDER_NOT_FOUND = 2;
	const static int NO_HEADER_FILE_FOUND_IN_RTC = 3;

signals:
	void handleMergeDone();
	void mergeError(int code, QString description);
	void mergeStarted();
	void mergeFinished();
	void readStandardInput(QString text);

public slots:
	void handleStrated();
	void handleReadStandardOutput();
	void handleFinish(int code, QProcess::ExitStatus status);
	void setpaseProjectPath(QString path);
	void setpasaProjectPath(QString path);

private:
	QProcess *process;
	QString *paseProjectPath;
	QString *pasaProjectPath;
};

#endif // PASEMERGEFOD01_H
