
#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <Box2D/Common/b2Draw.h>

#include <qgraphicsitem.h>
#include <converter.h>
#include <qbrush.h>
#include <converter.h>



class debugger : public b2Draw
{
    friend class SceneManager;
    friend class GameManager;
    friend class Player;
    friend class Vehicle;

public:
    debugger();
    ~debugger();
    void log(int level, QString s);
    void debug();
    static const bool DEBUGGING = true;
private:
    const int debugLevel = 0;
    std::list<QGraphicsItem*> debug_items = std::list<QGraphicsItem*>();
    // b2Draw interface
public:
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    void DrawTransform(const b2Transform& xf);
    void Clear();
};

#endif // DEBUGGER_H
