
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
   explicit DashboardField(QWidget* parent = nullptr);
    virtual ~DashboardField(){}
protected:
    virtual QString fieldName() {return "FIELD: ";}
    virtual QWidget* ContentWidget(){ return new QLabel("VALUE");}
    QWidget* Content;

   protected slots:
   virtual void onUpButtonPressed()=0;
    virtual void onDownButtonPressed()=0;

private:
   QPushButton* downButton;
    QPushButton* upButton;
   QLabel* label;

};

#endif // DASHBOARDFIELD_H

#ifndef DEBUGGINGDASHBOARDMASS_H
#define DASHBOARDFIELD_H
#endif // DASHBOARDFIELD_H
