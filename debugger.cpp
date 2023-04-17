
#include "scenemanager.h"
#include <GameManager.h>


SceneManager::debugger::debugger() : b2Draw()
{

}
SceneManager::debugger::~debugger(){}
void SceneManager::debugger::log(int level, QString s)
{
    if (level >= debugLevel)
    {

        qDebug() << s;
    }
}
void SceneManager::debugger::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{

    QPolygonF* pt = new QPolygonF();
    *pt << QPointF(0,0) << QPointF(-10,-10)<< QPointF(10,10)<< QPointF(0,0)<< QPointF(-10,10)<< QPointF(10,-10);

    auto graphic_ = new QGraphicsPolygonItem();
    graphic_->setPolygon(*pt);
    graphic_->show();
}
void SceneManager::debugger::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
    {

    QPolygonF* pts = new QPolygonF();

    for (int i = 0; i < vertexCount; i++)
    {
        *pts << converter::convertToQPointF(vertices[i]);
    }
    auto graphic_ = new QGraphicsPolygonItem();

    graphic_->setPolygon(*pts);
    graphic_->show();

    debug_items.push_back(graphic_);
    graphic_->setBrush(QBrush(Qt::red));
    SceneManager::Instance()->addToScene(graphic_);

    };
void SceneManager::debugger::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
    {
        qDebug()<< "Hello2";
    };
void SceneManager::debugger::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
    {
        qDebug()<< "Hello3";
    };
void SceneManager::debugger::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
    {
        qDebug()<< "Hello4";
    };
void SceneManager::debugger::DrawTransform(const b2Transform& xf)
    {
        qDebug()<< "Hello5";
    };
    void SceneManager::debugger::Clear()
    {
        if (!debug_items.empty())
        {
        for (QGraphicsItem* q : debug_items)
        {
        q->scene()->removeItem(q);
        }
        }
        debug_items.clear();
    }

    void SceneManager::debugger::debug()
    {

    }

    int SceneManager::debugger::debugMass(int change)
    {
        auto def = GameManager::Instance()->player->getVehicle()->changeMass(change);


    }

