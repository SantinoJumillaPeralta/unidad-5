#include "Game.h"
#include "Box2DHelper.h"
#include <iostream>

Game::Game(int ancho, int alto, std::string titulo) {
    wnd = new RenderWindow(VideoMode(ancho, alto), titulo);
    wnd->setVisible(true);
    fps = 60;
    wnd->setFramerateLimit(fps);
    frameTime = 1.0f / fps;
    SetZoom();
    InitPhysics();
}

void Game::Loop() {
    while (wnd->isOpen()) {
        wnd->clear(clearColor);
        DoEvents();
        CheckCollitions();
        UpdatePhysics();
        DrawGame();
        wnd->display();
    }
}

void Game::UpdatePhysics() {
    phyWorld->Step(frameTime, 8, 8);
    phyWorld->ClearForces();
    phyWorld->DebugDraw();
}

void Game::DrawGame() {
    // Dibujo de los elementos del juego
}

void Game::DoEvents() {
    Event evt;
    while (wnd->pollEvent(evt)) {
        switch (evt.type) {
        case Event::Closed:
            wnd->close();
            break;
        }
        ball1->SetAwake(true);
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            ball1->SetLinearVelocity(b2Vec2(-30.0f, 0.0f));
        }
    }
}

void Game::CheckCollitions() {
    // Implementación de la comprobación de colisiones
}

void Game::SetZoom() {
    View camara;
    camara.setSize(100.0f, 100.0f);
    camara.setCenter(50.0f, 50.0f);
    wnd->setView(camara);
}

Game::~Game() {
    //no deconstructor?
}

void Game::InitPhysics() {
    phyWorld = new b2World(b2Vec2(0.0f, 9.8f));
    debugRender = new SFMLRenderer(wnd);
    debugRender->SetFlags(UINT_MAX);
    phyWorld->SetDebugDraw(debugRender);

    b2Body* groundBody = Box2DHelper::CreateComplexRectangularStaticBody(phyWorld, 100, 10, 5);
    groundBody->SetTransform(b2Vec2(50.0f, 100.0f), 0.0f);

    b2Body* leftWallBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 10, 100);
    leftWallBody->SetTransform(b2Vec2(0.0f, 50.0f), 0.0f);

    b2Body* rightWallBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 10, 100);
    rightWallBody->SetTransform(b2Vec2(100.0f, 50.0f), 0.0f);

    b2Body* TopWallBody = Box2DHelper::CreateRectangularStaticBody(phyWorld, 100, 10);
    TopWallBody->SetTransform(b2Vec2(50.0f, 0.0f), 0.0f);

    b2Body* cuadrito = Box2DHelper::CreateRectangularDynamicBody(phyWorld, 4, 4, 3, 0.4f, 0.4f);
    cuadrito->SetTransform(b2Vec2(5, 5), 0);

    b2Body* cuadrito2 = Box2DHelper::CreateRectangularDynamicBody(phyWorld, 4, 4, 3, 0.4f, 0.4f);
    cuadrito2->SetTransform(b2Vec2(8, 5), 0);

    Ragdoll doll(phyWorld, b2Vec2(20, 10));
}
