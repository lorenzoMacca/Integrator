#ifndef DEFINEBUILDWIDGET_H
#define DEFINEBUILDWIDGET_H

#include <QWidget>
#include <QDate>
#include <QList>
#include <QListIterator>
#include "src/core/entities/build.h"
#include "src/core/data/data.h"
#include "src/core/util/util.h"

namespace Ui {
class DefineBuildWidget;
}

class DefineBuildWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DefineBuildWidget(Data *d, QWidget *parent = 0);
    ~DefineBuildWidget();

private:
    Ui::DefineBuildWidget *ui;
    Build *m_build;
    Data *m_data;
};

#endif // DEFINEBUILDWIDGET_H
