#include "UIComponentSoftware.h"

UIComponentSoftware::UIComponentSoftware(QString name, QString version, QString description, QWidget *parent):QWidget(parent)
{
    this->m_name_label = new QLabel(name, parent);
    this->m_version_line_edit = new QLineEdit(version, parent);
    this->m_description_line_edit = new QLineEdit(description, parent);
}

UIComponentSoftware &UIComponentSoftware::operator=(const UIComponentSoftware &other)
{
    this->setParent(other.parentWidget());
    this->m_name_label = new QLabel(other.nameLabel()->text(), other.parentWidget());
    this->m_version_line_edit = new QLineEdit(other.versionLineEdit()->text(), other.parentWidget());
    this->m_description_line_edit = new QLineEdit(other.descriptionLineEdit()->text(), other.parentWidget());
    return *this;
}

UIComponentSoftware::UIComponentSoftware(const UIComponentSoftware &other):QWidget(other.parentWidget())
{
    this->m_name_label = new QLabel(other.nameLabel()->text(), other.parentWidget());
    this->m_version_line_edit = new QLineEdit(other.versionLineEdit()->text(), other.parentWidget());
    this->m_description_line_edit = new QLineEdit(other.descriptionLineEdit()->text(), other.parentWidget());
}

bool UIComponentSoftware::operator==(const UIComponentSoftware &other)
{
    if( this->m_name_label->text() == other.nameLabel()->text() )
        return true;
    return false;
}

QLabel* UIComponentSoftware::nameLabel()const
{
    return this->m_name_label;
}

QLineEdit* UIComponentSoftware::versionLineEdit()const
{
    return this->m_version_line_edit;
}

QLineEdit* UIComponentSoftware::descriptionLineEdit()const
{
    return this->m_description_line_edit;
}
