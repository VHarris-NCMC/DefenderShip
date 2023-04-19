
#ifndef DASHBOARDFIELD_H
#define DASHBOARDFIELD_H

#include <QWidgetItem>
#include <QWidget>
#include <QGridLayout>
#include <QProgressBar>
#include <qlabel.h>
#include <qpushbutton.h>

class DashboardField : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardField(QWidget* parent = nullptr, QString fieldName = "DASHBOARD_DEBUG", QWidget* = new QLabel ("DEFAULT WIDGET"));
    virtual ~DashboardField(){}
protected:
    QWidget* Content;
    QLabel* label;
protected slots:
    virtual void onUpButtonPressed()=0;
    virtual void onDownButtonPressed()=0;

private:
   QPushButton* downButton;
    QPushButton* upButton;

};

#endif // DASHBOARDFIELD_H

#ifndef DEBUGGINGDASHBOARDMASS_H
#define DASHBOARDFIELD_H
#endif // DASHBOARDFIELD_H
