#include <cstdio>
#include <windows.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SFMLAssetManager.cpp"
#include "GameWindow.cpp"
#include "EntityManager.cpp"

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
    int gameWidth = 600;
    int gameHeight = 600;

    GameWindow mainWindow = GameWindow(gameWidth, gameHeight, "C++ SFML Game Test");
    SFMLAssetManager aMan = SFMLAssetManager();
    EntityManager eMan = EntityManager();

    aMan.loadImageAsset("explosion", "res/explosion.png");
    aMan.loadImageAsset("chars-med", "res/chars-med.png");

    eMan.generateSpriteSet("ss-explosion", aMan.getImageAsset("explosion"), 0, 0, 50, 50, 6);
    eMan.generateSpriteSet("ss-explosion-t", aMan.getImageAsset("explosion"), 0, 0, 30, 30, 5);

    eMan.addEntity("ss-explosion", 0, 100.0f, 100.0f);

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
            eMan.moveEntityAtIndex(0, -3, 0);
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            eMan.moveEntityAtIndex(0, 3, 0);
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            eMan.moveEntityAtIndex(0, 0, -3);
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            eMan.moveEntityAtIndex(0, 0, 3);
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