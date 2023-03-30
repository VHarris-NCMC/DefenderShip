#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H



#include <Player.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>



class SceneManager
{
    public:
        SceneManager();

        void keyPressEvent(QKeyEvent* event);
        void add(QGraphicsItem q);






    private:

        QGraphicsScene* scene;
        Player * player;
        QGraphicsView* view;
        void generateSceneWithPlayer();
        void setWindowSize();
        Q_PROPERTY(SceneManager* smInstance READ smInstance WRITE setSmInstance NOTIFY smInstanceChanged)
};

#endif // SCENEMANAGER_H
