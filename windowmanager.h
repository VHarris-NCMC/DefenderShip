#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <mutex>
#include <QScreen>
#include<QApplication>
#include <qgraphicsview.h>
#include <QBoxLayout>
#include <mainwindow.h>>
#include <dashboard.h>
class WindowManager
{
	public:
		friend class SceneManager;
		static WindowManager* Instance()
		{
			//lock
			std::lock_guard<std::mutex> lock(mutex_);
			//If instance does not exist, create a new one
			if (instance_ == nullptr){ instance_= new WindowManager();}
			// return signleton instance;
			return instance_;
		}
		static QGraphicsView* getView()
		{
			return Instance()->view;
		}

		static QSize getCurrentScreenSize()
		{
            return qApp->primaryScreen()->availableSize();
        };

    private:
		WindowManager();
		~WindowManager();
		inline static std::mutex mutex_;
		inline static WindowManager* instance_ { nullptr};
		//Prevent Singleton from being copied.
		WindowManager(WindowManager const&);;
		void operator=(WindowManager const&);;
		QGraphicsView* view;
        MainWindow* window;


		void InitializeWIndow();
};

#endif // WINDOWMANAGER_H
