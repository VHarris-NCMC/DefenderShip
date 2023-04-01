#include "windowmanager.h"

WindowManager::WindowManager()
{
	InitializeWIndow();
}

WindowManager::~WindowManager(){}

WindowManager::WindowManager(const WindowManager&){}

void WindowManager::operator=(const WindowManager&){}


void WindowManager::InitializeWIndow()
{
	//Initialize 'view' (window)
	view = new QGraphicsView();
	//Set window size to match the screen size
	view->setFixedSize(getCurrentScreenSize());
	//Prevent Scrolling
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// Show window
	view->show();
	qDebug() << "View Size - Width: " << view->size().height() << "Height: " << view->size().width();
}
