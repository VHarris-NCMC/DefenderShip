
#include "dashboard.h"

#include <qlabel.h>

#include <Scenemanager.h>


Dashboard::Dashboard(QWidget* parent) : QDockWidget(parent)
{
    setParent(parent);
    show();
    setMinimumHeight(200);
    setMaximumSize(2500, 500);
    setBaseSize(2500, 200);
    QPalette* pal = new QPalette();
    pal->setColor(QPalette::Window, Qt::white);
    setFixedSize(baseSize());

    setFeatures(NoDockWidgetFeatures);
    setFeatures(DockWidgetVerticalTitleBar);

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
void Dashboard::addPanels(QLayout* layout)
{


}
void Dashboard::addFields(QGridLayout* grid, QWidget* widget)
{
    int col = 0;
    int row =0;

    for (std::pair<UI_BUTTON*, bool> kvp : fields)
    {
        if (kvp.second == true)
        {

            grid->addWidget(kvp.first, ++row, col,  Qt::AlignLeft);


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

