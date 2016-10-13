#include "pasemergefod01.h"

PaseMergeFod01::PaseMergeFod01(QObject *parent)
	: QObject(parent)
{
	this->paseProjectPath = new QString("");
	this->pasaProjectPath = new QString("");
}

PaseMergeFod01::~PaseMergeFod01()
{

}

void PaseMergeFod01::run()
{
	// the program is present.
	qDebug() << "run started";


	//check whether the paths are correct or not
	QDir paseDirQD(*this->paseProjectPath);
	if(!paseDirQD.exists()){
		qDebug() << "Folder not find: " << *this->paseProjectPath;
		emit mergeError(PaseMergeFod01::PASE_FOLDER_NOT_FOUND, "Folder not found: " + *this->paseProjectPath);
		return;
	}
	QDir pasaDirQD(*this->pasaProjectPath);
	if(!pasaDirQD.exists()){
		qDebug() << "Folder not find: " << *this->pasaProjectPath;
		emit mergeError(PaseMergeFod01::PASA_FOLDER_NOT_FOUND, "Folder not found: " + *this->pasaProjectPath);
		return;
	}

	this->process = new QProcess(this);
	this->process->setObjectName("PASA_MERGE_PROCESS");

	connect(this->process, SIGNAL(started()),
		    this, SLOT(handleStrated()));
	connect(this->process, SIGNAL(readyReadStandardOutput()), 
		    this, SLOT(handleReadStandardOutput()));
	connect(this->process, SIGNAL(finished(int,QProcess::ExitStatus)), 
		    this, SLOT(handleFinish(int,QProcess::ExitStatus)));
	QStringList arguments;
	arguments <<*(this->paseProjectPath) << *(this->pasaProjectPath); 
	this->process->start("script/merge/PASACreateLib_HON01_FOD01.cmd", arguments);
}

void PaseMergeFod01::handleStrated()
{
	qDebug() << "Process " << this->process->objectName() << " has started";
	emit mergeStarted();
}

void PaseMergeFod01::handleReadStandardOutput(){
    //qDebug() << "Ready to read";
    //qDebug() << this->process->readAllStandardOutput();
	emit readStandardInput(this->process->readAllStandardOutput());
}

void PaseMergeFod01::handleFinish(int code, QProcess::ExitStatus status)
{
	qDebug() << "Process has exited " << code << " - " << status;
	if(code != 0){
		emit mergeError(code,"");
	}
	emit mergeFinished();
}

void PaseMergeFod01::setpaseProjectPath(QString path)
{
	*(this->paseProjectPath) = path;
}

void PaseMergeFod01::setpasaProjectPath(QString path)
{
	*(this->pasaProjectPath) = path;
}