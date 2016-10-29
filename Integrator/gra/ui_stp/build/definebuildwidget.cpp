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

    QListIterator<UIComponentSoftware> iterComponents(this->getUIComponentSoftwares());

    QGridLayout *layout = new QGridLayout(this);
    int i=0;

    layout->addWidget(new QLabel("Component", this), i, 0);
    layout->addWidget(new QLabel("Version", this), i, 1);
    layout->addWidget(new QLabel("Description", this), i, 2);
    i++;

    while( iterComponents.hasNext())
    {
        UIComponentSoftware c = iterComponents.next();
        layout->addWidget(c.nameLabel(), i, 0);
        layout->addWidget(c.versionLineEdit(), i, 1);
        layout->addWidget(c.descriptionLineEdit(), i, 2);
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

QList<UIComponentSoftware> DefineBuildWidget::getUIComponentSoftwares()
{
    QList<UIComponentSoftware> ui_component_softwares;
    QList<ComponentSoftware> compnents = this->m_data->settingData()->getComponentsSoftware();
    QListIterator<ComponentSoftware> iterComponents(compnents);
    while( iterComponents.hasNext())
    {
         ComponentSoftware c = iterComponents.next();
         ui_component_softwares.append(UIComponentSoftware(c.name(), c.version(), c.description(), this));
    }
    return ui_component_softwares;
}
