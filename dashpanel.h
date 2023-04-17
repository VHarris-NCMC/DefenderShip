
#ifndef DASHPANEL_H
#define DASHPANEL_H
#include <QLayoutItem>
#include <QWidget>



class DashPanel : public QWidget
{
private:
    const QSize MAX_SIZE = QSize(600,400);
    const QSize MIN_SIZE = QSize(20,40);
    const QSize HINT_SIZE = QSize(400, 200);

    // QLayoutItem interface
public:
     DashPanel(QWidget* parent);
    ~DashPanel(){};
    QSize sizeHint() const override {return HINT_SIZE;}


};

#endif // DASHPANEL_H
