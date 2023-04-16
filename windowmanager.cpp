#include "windowmanager.h"



WindowManager::WindowManager()
{
	InitializeWIndow();
    window = new MainWindow();
}

WindowManager::~WindowManager(){}

WindowManager::WindowManager(const WindowManager&){}

void WindowManager::operator=(const WindowManager&){}


void WindowManager::InitializeWIndow()
{
	//Initialize 'view' (window)
    window = new MainWindow();
    window->activateWindow();



    view = new QGraphicsView();



	//Prevent Scrolling
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// Show window

    window->setCentralWidget(view);
    window->addDockWidget(Qt::BottomDockWidgetArea, new Dashboard());
    window->showMaximized();
    window->show();

}

