#ifndef DEFINEBUILDWIDGET_H
#define DEFINEBUILDWIDGET_H

#include <QWidget>
#include <QDate>
#include <QList>
#include <QListIterator>
#include <QGridLayout>
#include <QList>
#include <QListIterator>
#include "src/core/entities/component.h"
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
    explicit DefineBuildWidget(int index, Data *d, QWidget *parent = 0);
    ~DefineBuildWidget();

public slots:
    void handleBuildNameChanged(QString n);

signals:
    void buildNameChanged(int index, QString n);

private:
    Ui::DefineBuildWidget *ui;
    Build *m_build;
    Data *m_data;
    int m_index;
};

#endif // DEFINEBUILDWIDGET_H
