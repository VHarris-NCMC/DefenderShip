
#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include <QWidgetItem>
#include <QWidget>
#include <QGridLayout>
#include <QProgressBar>
#include <qlabel.h>
#include <qpushbutton.h>

class UI_BUTTON : public QWidget
{
    Q_OBJECT
public:
    explicit UI_BUTTON(QWidget* parent = nullptr, QString fieldName = "DASHBOARD_DEBUG", QWidget* = new QLabel ("DEFAULT WIDGET"));
    virtual ~UI_BUTTON(){}
protected:
    QWidget* Content;
    QLabel* label;
    QPushButton* downButton;
    QPushButton* upButton;
protected slots:
    virtual void onUpButtonPressed()=0;
    virtual void onDownButtonPressed()=0;



};

#endif // UI_BUTTON_H

#ifndef DEBUGGINGDASHBOARDMASS_H
#define DASHBOARDFIELD_H
#endif // DASHBOARDFIELD_H
