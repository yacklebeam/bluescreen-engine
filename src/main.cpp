#include <cstdio>
#include <windows.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SFMLAssetManager.cpp"
#include "GameWindow.cpp"
#include "EntityManager.cpp"
#include "SFMLInputManager.cpp"

#ifdef RELEASE
int WINAPI
WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
#else
int
main()
#endif
{
    enum Game_Action
    {
        MOVE_LEFT,
        MOVE_UP,
        MOVE_RIGHT,
        MOVE_DOWN
    };

    int gameWidth = 600;
    int gameHeight = 600;

    GameWindow mainWindow = GameWindow(gameWidth, gameHeight, "C++ SFML Game Test");
    SFMLAssetManager aMan = SFMLAssetManager();
    EntityManager eMan = EntityManager();

    aMan.loadImageAsset("explosion", "res/explosion.png");
    aMan.loadImageAsset("chars-med", "res/chars-med.png");

    eMan.generateSpriteSet("ss-explosion", aMan.getImageAsset("explosion"), 0, 0, 50, 50, 6);
    eMan.generateSpriteSet("ss-explosion-t", aMan.getImageAsset("explosion"), 0, 0, 30, 30, 5);
    eMan.generateSpriteSet("ss-chars-med", aMan.getImageAsset("chars-med"), 0, 120, 10, 10, 10);

    eMan.addEntity("ss-chars-med", 0, 100.0f, 100.0f);
    eMan.addEntity("ss-chars-med", 1, 112.0f, 100.0f);
    eMan.addEntity("ss-chars-med", 2, 124.0f, 100.0f);

    int frameCount = 0;

    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) mainWindow.close();
        }

        //TEST CODE, Working on SFMLInputProcessor
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            eMan.moveEntityAtIndex(-1, -3, 0);
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            eMan.moveEntityAtIndex(-1, 3, 0);
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            eMan.moveEntityAtIndex(-1, 0, -3);
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            eMan.moveEntityAtIndex(-1, 0, 3);
        }      

        mainWindow.clear();
        for(int i = 0; i < eMan.getEntityCount(); ++i)
        {
            if(eMan.hasEntityAtIndex(i))
            {
                eMan.updateEntityAtIndex(i, frameCount);
                mainWindow.draw(*eMan.getSpriteAtIndex(i));
            }
        }
        mainWindow.display();

        frameCount++;
        if(frameCount == 100) frameCount = 0;
    }

    return 0;
}