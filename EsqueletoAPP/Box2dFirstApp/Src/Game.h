#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.h"
#include <list>
#include "Box2DHelper.h"

using namespace sf;

class Game {
private:
    int alto;
    int ancho;
    RenderWindow* wnd;
    Color clearColor;
    b2World* phyWorld;
    SFMLRenderer* debugRender;
    float frameTime;
    int fps;
    b2Body* ball1;
    b2Body* ball2;
    b2Body* joint;
    b2MouseJoint* mouseJoint;

public:
    Game(int ancho, int alto, std::string titulo);
    void CheckCollitions();
    ~Game(void);
    void InitPhysics();
    void Loop();
    void UpdatePhysics();
    void DrawGame();
    void DoEvents();
    void SetZoom();
};
