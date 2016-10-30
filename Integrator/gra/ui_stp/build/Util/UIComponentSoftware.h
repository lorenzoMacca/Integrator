#ifndef UICOMPONENT_SOFTWARE_H
#define UICOMPONENT_SOFTWARE_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

class UIComponentSoftware : public QWidget{
    
    Q_OBJECT
    
public:
    UIComponentSoftware(QString name, QString version, QString description, QWidget *parent);
    UIComponentSoftware(const UIComponentSoftware &other);
    UIComponentSoftware &operator=(const UIComponentSoftware &other);
    bool operator==(const UIComponentSoftware &other);
    QLabel* nameLabel()const;
    QLineEdit* versionLineEdit()const;
    QLineEdit* descriptionLineEdit()const;
    QCheckBox* isInCheckBox()const;

private:
    QLabel *m_name_label;
    QLineEdit *m_version_line_edit;
    QLineEdit *m_description_line_edit;
    QCheckBox *m_isIn_check_box;

};

#endif
