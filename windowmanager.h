#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <mutex>
#include <QScreen>
#include<QApplication>
#include <qgraphicsview.h>
#include <QBoxLayout>
#include <mainwindow.h>
#include <dashboard.h>

class WindowManager
{
    friend class SceneManager;
    friend class MAINCONTROLLER;
public:
    WindowManager();
    static QSize getCurrentScreenSize()
    {

        return qApp->primaryScreen()->availableSize();

    };

    void closeMenu();
private:
		~WindowManager();
		inline static std::mutex mutex_;
		inline static WindowManager* instance_ { nullptr};
		//Prevent Singleton from being copied.
		WindowManager(WindowManager const&);;
		void operator=(WindowManager const&);;
        QDockWidget* leftWidget;
		QGraphicsView* view;
        MainWindow* window;


		void InitializeWIndow();
};

#endif // WINDOWMANAGER_H
