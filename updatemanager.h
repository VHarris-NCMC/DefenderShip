#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include <QObject>
#include <scenemanager.h>
#include <CONFIG.h>

class UpdateManager : public QObject
{

		Q_OBJECT
		friend class SceneManager;
	public:
		UpdateManager();
		QTimer* timer;
	private slots:
		void update();
};

#endif // UPDATEMANAGER_H
