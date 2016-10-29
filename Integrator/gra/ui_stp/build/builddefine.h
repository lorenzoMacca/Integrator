#ifndef BUILDDEFINE_H
#define BUILDDEFINE_H

#include <QWidget>
#include "definebuildwidget.h"
#include "src/core/entities/integration_plan.h"

namespace Ui {
class BuildDefine;
}

class BuildDefine : public QWidget
{
    Q_OBJECT

public:
    explicit BuildDefine(Data *d, int buildNumber, IntegrationPlan *i, QWidget *parent = 0);
    ~BuildDefine();

public slots:
    void handleBackButtonPressed();
    void handlBuildNameChange(int index, QString n);

signals:
    void backButtonPressed();

private:
    Ui::BuildDefine *ui;
    IntegrationPlan *m_i;
    int m_buildNumber;
};

#endif // BUILDDEFINE_H
