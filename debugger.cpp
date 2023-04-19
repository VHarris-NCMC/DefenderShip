
#include "exceptions.cpp"
#include "scenemanager.h"
#include <maincontroller.h>
#include <QLineF>



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
    if(!DEBUGGING)
    {
        return;
    }
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
    MAINCONTROLLER::ADD_TO_SCENE(graphic_);

    };
void SceneManager::debugger::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
    {
    qDebug() << "DrawCircle graphical debug not implemented";
        throw ("Not implemented)");
    };
void SceneManager::debugger::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
    {
        qDebug() << "DrawSolidCircle graphical debug not implemented";
        throw ("Not implemented)");
    };
void SceneManager::debugger::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
    {
        QLineF* line = new QLineF(converter::convertToQPointF(p1), converter::convertToQPointF(p2));
        auto graphic_ = new QGraphicsLineItem();

        graphic_->setLine(*line);
        graphic_->show();

        debug_items.push_back(graphic_);
        graphic_->setPen(QPen(Qt::blue));
        MAINCONTROLLER::ADD_TO_SCENE(graphic_);
    };
void SceneManager::debugger::DrawTransform(const b2Transform& xf)
    {
        qDebug() << "DrawTransform graphical debug not implemented";
        throw ("Not implemented)");
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

    float32 SceneManager::debugger::debugMass(double change)
    {
        try {
        Player* player = GameManager::GetPlayer();
        if (player == nullptr) {
        throw std::runtime_error("Player not instantiated");
        }
        return player->getVehicle()->debugChangeMass(change);
        } catch (const std::exception& ex) {
        qDebug() << "Error debugging mass: " << ex.what();
        return 0;
        }
    }
    float32 SceneManager::debugger::debugThrust(double change)
    {
        try {
        Player* player = GameManager::GetPlayer();
        if (player == nullptr) {
        throw std::runtime_error("Player not instantiated");
        }
        return GameManager::GetPlayer()->getVehicle()->debugChangeThrust(change);
        } catch (const std::exception& ex) {
        qDebug() << "Error debugging thrust: " << ex.what();
        return 0;
        }
    }

    float32 SceneManager::debugger::debugMaxThrust(double change)
    {
        try {
        Player* player = GameManager::GetPlayer();
        if (player == nullptr) {
        throw std::runtime_error("Player not instantiated");
        }
        return GameManager::GetPlayer()->getVehicle()->debugChangeMaxThrust(change);
        } catch (const std::exception& ex) {
        qDebug() << "Error debugging max thrust: " << ex.what();
        return 0;
        }
    }

    float32 SceneManager::debugger::debugLinearDamping(double change)
    {
        try {
        Player* player = GameManager::GetPlayer();
        if (player == nullptr) {
        throw std::runtime_error("Player not instantiated");
        }
        return GameManager::GetPlayer()->getVehicle()->debugChangeLinearDampening(change);
        } catch (const std::exception& ex) {
        qDebug() << "Error debugging max thrust: " << ex.what();
        return 0;
        }
    }
