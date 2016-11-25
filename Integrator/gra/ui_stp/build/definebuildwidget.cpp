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
        this->ui->m_ui_start_date->addItem(currentDate.toString(), currentDate);
        this->ui->m_ui_upload_date->addItem(currentDate.toString(), currentDate);
        this->ui->m_ui_delivery_date->addItem(currentDate.toString(), currentDate);
    }

    this->m_ui_components = this->getUIComponentSoftwares();

    QGridLayout *layout = new QGridLayout(this);
    int i=0;

    layout->addWidget(new QLabel("Is it in?", this), i, 0);
    layout->addWidget(new QLabel("Component", this), i, 1);
    layout->addWidget(new QLabel("Version", this), i,   2);
    layout->addWidget(new QLabel("Description", this), i, 3);

	for(; i<this->m_ui_components.size();)
    {
		int j = i+1;
		layout->addWidget(this->m_ui_components.at(i).isInCheckBox(), j, 0);
        layout->addWidget(this->m_ui_components.at(i).nameLabel(), j, 1);
        layout->addWidget(this->m_ui_components.at(i).versionLineEdit(), j, 2);
        layout->addWidget(this->m_ui_components.at(i).descriptionLineEdit(), j, 3);
		i++;
    }

    this->ui->m_component->setLayout(layout);

    connect(this->ui->m_ui_build_name, SIGNAL(textEdited(QString)), this, SLOT(handleBuildNameChanged(QString)));
    connect(this->ui->m_ui_save, SIGNAL(released()), this, SLOT(handleSaveButtonPressed()));
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
         ui_component_softwares.append(UIComponentSoftware(c.name(), c.version(), c.description(), 0));
    }
    return ui_component_softwares;
}

void DefineBuildWidget::handleSaveButtonPressed()
{
    //save build info
    QString build_name = this->ui->m_ui_build_name->text();
    this->m_data->integrationPlan()->buildsMod()[this->m_index].setName(build_name);
    QString build_description = this->ui->m_ui_desription->toPlainText();
    this->m_data->integrationPlan()->buildsMod()[this->m_index].setDescription(build_description);
    QDate start_date = this->ui->m_ui_start_date->itemData(this->ui->m_ui_start_date->currentIndex()).toDate();
    this->m_data->integrationPlan()->buildsMod()[this->m_index].setStartDate(start_date);
    QDate upload_date = this->ui->m_ui_upload_date->itemData(this->ui->m_ui_upload_date->currentIndex()).toDate();
    this->m_data->integrationPlan()->buildsMod()[this->m_index].setUploadDay(upload_date);
    QDate delivery_date = this->ui->m_ui_delivery_date->itemData(this->ui->m_ui_delivery_date->currentIndex()).toDate();
    this->m_data->integrationPlan()->buildsMod()[this->m_index].setDeliveryDay(delivery_date);
    this->m_data->integrationPlan()->buildsMod()[this->m_index].componentsMod().clear();
    QListIterator<UIComponentSoftware> iter(this->m_ui_components);
    while(iter.hasNext())
    {
        UIComponentSoftware ui_component = iter.next();
		bool isChecked =  ui_component.isInCheckBox()->isChecked();
        if(isChecked)
        {
            ComponentSoftware current_component_software(ui_component.nameLabel()->text(), ui_component.versionLineEdit()->text(), ui_component.descriptionLineEdit()->text(), 0);
            this->m_data->integrationPlan()->buildsMod()[this->m_index].addComponent(current_component_software);
        }
    }
    //end save build info

    qDebug() << "Saving the following build:";
    qDebug() << "Build name: " << this->m_data->integrationPlan()->buildsMod()[this->m_index].name();
    qDebug() << "Description" << this->m_data->integrationPlan()->buildsMod()[this->m_index].description();
    qDebug() << "Start date: " << this->m_data->integrationPlan()->buildsMod()[this->m_index].start_date().toString();
    qDebug() << "Upload date: " << this->m_data->integrationPlan()->buildsMod()[this->m_index].upload_day().toString();
    qDebug() << "Delivery date: " << this->m_data->integrationPlan()->buildsMod()[this->m_index].delivery_day().toString();
    int numComponents = this->m_data->integrationPlan()->buildsMod()[this->m_index].components().size();
    qDebug() << "N° components: " + QString::number(numComponents);
    if(numComponents > 0)
    {
        qDebug() << "Components:";
        QListIterator<ComponentSoftware> cp_iter(this->m_data->integrationPlan()->buildsMod()[this->m_index].components());
        while(cp_iter.hasNext())
        {
            ComponentSoftware cs = cp_iter.next();
            qDebug() << "  --> " + cs.name() + " " + cs.version() + " " + cs.description();
        }
    }
}
