#include "windowmanager.h"

#include <MenuDock.h>



WindowManager::WindowManager()
{
	InitializeWIndow();
   view->setStyleSheet("background-image: url(:/images/src/SpaceBackground.png);");
    window->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

WindowManager::~WindowManager()
{
}

WindowManager::WindowManager(const WindowManager&){}

void WindowManager::operator=(const WindowManager&){}


void WindowManager::InitializeWIndow()
{
	//Initialize 'view' (window)
    window = new MainWindow();
    window->activateWindow();



    view = new QGraphicsView();


    // Configure Background
    //view->setBackgroundBrush(QPixmap(BACKGROUND, "png", Qt::AutoColor));
    auto viewRect  = new QRect(QPoint(-1000, 1000), QPoint(1000, -1000));
    view->setAutoFillBackground(true);


	//Prevent Scrolling
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Show window

    window->setCentralWidget(view);

    window->addDockWidget(Qt::BottomDockWidgetArea, new Dashboard());
    leftWidget = new MenuDock();
    window->addDockWidget(Qt::LeftDockWidgetArea,leftWidget);
    window->showMaximized();
    window->show();

}
void WindowManager::closeMenu()
{
    window->removeDockWidget(leftWidget);
}

