#ifndef UI_DEFINE_STP_H
#define UI_DEFINE_STP_H

#include <QWidget>
#include <QDate>
#include <QMessageBox>
#include "src/core/data/data.h"
#include "src/core/entities/integration_plan.h"
#include "QStringList"
#include "QStringListIterator"

namespace Ui {
class Form;
}

class UIDefineSTP : public QWidget
{
    Q_OBJECT

public:
    explicit UIDefineSTP(Data *d, QWidget *parent = 0);
    ~UIDefineSTP();

public slots:
    void nextButtonClicketSlot();
    void next();
    void handleIsMergeCheckBox(int);

signals:
    void integrationPlanInitializedAfterCallToNextButton();
    void nextButtonPressed(int i);

private:
    Ui::Form *ui;
    Data *m_data;
};

#endif // UI_DEFINE_STP_H
