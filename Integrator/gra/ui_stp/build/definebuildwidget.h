#ifndef DEFINEBUILDWIDGET_H
#define DEFINEBUILDWIDGET_H

#include <QWidget>
#include "src/core/entities/build.h"

namespace Ui {
class DefineBuildWidget;
}

class DefineBuildWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DefineBuildWidget(QWidget *parent = 0);
    ~DefineBuildWidget();

private:
    Ui::DefineBuildWidget *ui;
    Build *m_build;
};

#endif // DEFINEBUILDWIDGET_H
