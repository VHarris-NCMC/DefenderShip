
#include "dashboard.h"

Dashboard::Dashboard(QWidget* parent) : QDockWidget(parent)
{
    setParent(parent);
    show();
    setFeatures(NoDockWidgetFeatures);
    setMinimumHeight(150);
    setLayout(new QGridLayout());









}

