
#include "MenuDock.h"

#include <DashPanel.h>

    MenuDock::MenuDock(QWidget* parent) : QDockWidget(parent)
    {
        setParent(parent);
        show();
        setMinimumHeight(400);
        setMaximumSize(500,2500);
        setBaseSize(200, 2500);
        QPalette* pal = new QPalette();
        pal->setColor(QPalette::Window, Qt::white);
        setFixedSize(baseSize());

        setFeatures(NoDockWidgetFeatures);
        setFeatures(DockWidgetVerticalTitleBar);
        setFeatures(DockWidgetClosable);

        QWidget* widget = new DashPanel(this);

        widget->setFixedSize(size());
        setAutoFillBackground(true);
        setPalette(*pal);
        setWidget(widget);
        widget->setGeometry(1000,1000,1000,1000);
        widget->setBaseSize(1000,1000);
        pal->setColor(QPalette::Window, Qt::gray);
        widget->setPalette(*pal);
        widget->setAutoFillBackground(true);
        widget->show();
        QGridLayout* grid = new QGridLayout(widget);

        widget->setLayout(grid);
        widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        addFields(grid, widget);

        show();







    }
    void MenuDock::addPanels(QLayout* layout)
    {


    }
    void MenuDock::addFields(QGridLayout* grid, QWidget* widget)
    {
        int col = 0;
        int row =0;

        for (std::pair<UI_BUTTON*, bool> kvp : fields)
        {
            if (kvp.second == true)
            {
                grid->addWidget(kvp.first, ++row, col,  Qt::AlignTop);
            }
            else{
                grid->addWidget(new QWidget());
            }
            if (row >= ROWS)
            {
                col++;
                row = 0;
            }


        }

    }
