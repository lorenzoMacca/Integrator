#include "definebuildwidget.h"
#include "ui_definebuildwidget.h"

DefineBuildWidget::DefineBuildWidget(int index, Data *d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefineBuildWidget)
{
    ui->setupUi(this);
    this->m_data = d;
    this->m_index = index;

    QUtilSTP util(this);
    QList<QDate> dates = util.getDatesBetween(this->m_data->integrationPlan()->start_date(), this->m_data->integrationPlan()->due_date());
    QListIterator<QDate> iter(dates);
    while(iter.hasNext())
    {
        QDate currentDate = iter.next();
        qDebug() << currentDate.toString();
        this->ui->m_ui_start_date->addItem(currentDate.toString(), currentDate);
        this->ui->m_ui_upload_date->addItem(currentDate.toString(), currentDate);
        this->ui->m_ui_delivery_date->addItem(currentDate.toString(), currentDate);
    }

    QList<ComponentSoftware> compnents = d->settingData()->getComponentsSoftware();
    QListIterator<ComponentSoftware> iterComponents(compnents);

    QGridLayout *layout = new QGridLayout(this);
    int i=0;
    while( iterComponents.hasNext())
    {
        ComponentSoftware c = iterComponents.next();
        layout->addWidget(new QLabel(c.name(), this), i, 0);
        layout->addWidget(new QLineEdit(c.version(), this), i, 1);
        layout->addWidget(new QLineEdit(c.description(), this), i, 2);
        i++;
    }

    this->ui->m_component->setLayout(layout);

    connect(this->ui->m_ui_build_name, SIGNAL(textEdited(QString)), this, SLOT(handleBuildNameChanged(QString)));
}

DefineBuildWidget::~DefineBuildWidget()
{
    delete ui;
}

void DefineBuildWidget::handleBuildNameChanged(QString n)
{
    emit buildNameChanged(this->m_index, n);
}
