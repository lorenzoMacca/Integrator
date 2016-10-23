#ifndef BUILDDEFINE_H
#define BUILDDEFINE_H

#include <QWidget>
#include "definebuildwidget.h"

namespace Ui {
class BuildDefine;
}

class BuildDefine : public QWidget
{
    Q_OBJECT

public:
    explicit BuildDefine(QWidget *parent = 0);
    ~BuildDefine();

private:
    Ui::BuildDefine *ui;
};

#endif // BUILDDEFINE_H
