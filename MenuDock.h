
#ifndef MENUDOCK_H
#define MENUDOCK_H

#include <MenuButton.h>
#include <qdockwidget.h>
#include <qgridlayout.h>





class MenuDock: public QDockWidget
{
    Q_OBJECT
private:
    const int COLUMNS = 2;
    const int ROWS = 10;
public:
    MenuDock(QWidget* parent = nullptr);
    virtual ~MenuDock(){};



private:
    void addPanels(QLayout* layout);
    void addFields(QGridLayout* grid, QWidget* widget);


    std::map<UI_BUTTON*,bool> fields = {
                                            {new StartButton(this), true},
        {new TestButton(this), true},
        {new StartButton(this), true},
        {new StartButton(this), true}
    };


};

#endif // MENUDOCK_H
