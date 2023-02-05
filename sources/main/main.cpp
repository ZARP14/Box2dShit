#include <SFML/Graphics.hpp>

#include <iostream>

#include "domain/definiki.hpp"

#include "box2d/box2d.h"
#include "gui/gui.hpp"

void
doWorldStep(b2World world)
{
    float timeStep         = 1.0f / 60.0f;
    int velocityIterations = 6;
    int positionIterations = 2;
    for (int i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
    }
}

int
main()
{
    b2BodyDef groundBoxDef;
    b2Vec2 gravity(0.0f, -10.0f);
    b2World mB2dWorld(gravity);
    b2Body* groundBox;
    b2PolygonShape groundBoxShape;

    sf::Texture groundboxTexture;
    sf::IntRect groundBoxRect(0, 52, 1713, 1);
    sf::Sprite groundBoxSprite;

    groundBoxDef.position.Set(0.0f, -500.0f);
    groundBox = mB2dWorld.CreateBody(&groundBoxDef);
    groundBoxShape.SetAsBox(50.0f, 10.0f);
    groundBox->CreateFixture(&groundBoxShape, 0.0f);

    b2PolygonShape staticBox;
    staticBox.SetAsBox(1000.0f, 1.0f);
    b2FixtureDef staticFixtureDef;
    staticFixtureDef.shape = &staticBox;
    groundBox->CreateFixture(&staticFixtureDef);

    groundboxTexture.loadFromFile(TEXTURES_PATH + "flor.png");
    groundBoxSprite.setTexture(groundboxTexture);
    groundBoxSprite.setTextureRect(groundBoxRect);
    groundBoxSprite.setPosition(groundBox->GetPosition().x, -groundBox->GetPosition().y);
    Gui::global.vectorInput(groundBoxSprite);

    sf::Texture objectTexture;
    sf::IntRect objectRectangle(0, 0, 82, 53);
    sf::Sprite objectSprite;

    objectTexture.loadFromFile(TEXTURES_PATH + "playerTexture.png");
    objectSprite.setTexture(objectTexture);
    objectSprite.setPosition(500, 0);
    Gui::global.vectorInput(objectSprite);

    b2BodyDef bodyDef;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;

    b2Body* body;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(500.0f, .0f);
    bodyDef.gravityScale = 10.0f;
    body                 = mB2dWorld.CreateBody(&bodyDef);
    dynamicBox.SetAsBox(82.0f, 53.0f);
    fixtureDef.shape    = &dynamicBox;
    fixtureDef.density  = 10.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    float timeStep           = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int32 i = 0; true; ++i)
    {
        Gui::global.visualStarted();
        mB2dWorld.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle     = body->GetAngle();
        objectSprite.setPosition(position.x, -position.y);
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}