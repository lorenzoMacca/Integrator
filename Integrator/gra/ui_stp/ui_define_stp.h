#ifndef UI_DEFINE_STP_H
#define UI_DEFINE_STP_H

#include <QWidget>

namespace Ui {
class Form;
}

class UIDefineSTP : public QWidget
{
    Q_OBJECT

public:
    explicit UIDefineSTP(QWidget *parent = 0);
    ~UIDefineSTP();

private:
    Ui::Form *ui;
};

#endif // UI_DEFINE_STP_H
