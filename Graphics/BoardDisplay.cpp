//
// Created by tremo on 13/04/2025.
//

#include <SFML/Graphics.hpp>
#include "BoardDisplay.h"

#include <iostream>
using namespace bugs;
using namespace sf;

namespace graphics {

    void BoardDisplay::initBoardDisplay(const vector<Bug *> &bugs, GameBoard* &board, const int gridX, const int gridY)
    {
        gameBoard = board;
        boardBugs = bugs;
        gridWidth = gridX;
        gridHeight = gridY;
        RenderWindow window(VideoMode(displayWidth,displayHeight), boardTitle, Style::Default);
        gameWindow = &window;
        window.setFramerateLimit(30);

        const int cellWidth = (displayWidth - menuWidth) / (gridWidth + 1);
        const int cellHeight = displayHeight / (gridHeight + 1);
        int counter = 0;

        for (int i = 0; i <= gridWidth; i++)
        {
            for (int j = 0; j <= gridHeight; j++)
            {
                Position pos(i, j);
                auto tile = new RectangleShape(Vector2f(cellWidth, cellHeight));
                tile->setFillColor(counter % 2 == 0 ? boardColor1 : boardColor2);
                tile->setPosition(Vector2f(i * cellWidth, j * cellHeight));
                boardMap[pos.toString()] = tile;
                boardTiles.push_back(tile);
                counter++;
            }
            counter++;
        }
        initBugCircles();
        runDisplay();
    }

    void BoardDisplay::runDisplay()
    {
        gameWindow->clear();

        for (const auto &tile: boardTiles)
        {
            gameWindow->draw(*tile);
        }

        updateBoardDisplay();

        gameWindow->display();

        while (gameWindow->isOpen())
        {
            Event event;
            while (gameWindow->pollEvent(event))
            {
                if (event.type == Event::Closed)
                    gameWindow->close();

                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::Space)
                    {
                        gameBoard->tapBoard();
                        updateBoardDisplay();
                    }
                }
            }
        }

        cout << "Window closing" << endl;
    }

    void BoardDisplay::initBugCircles()
    {
        for (const auto &bug: boardBugs)
        {
            auto pos = bug->getPosition();
            const auto tile = boardMap[pos.toString()];
            auto* bugCircle = new CircleShape(tile->getSize().x / 2);

            if (bug->getBugType() == "Crawler")
            {
                bugCircle->setFillColor(crawlerColor);
            }
            else if (bug->getBugType() == "Hopper")
            {
                bugCircle->setFillColor(hopperColor);
            }

            bugCircle->setPosition(tile->getPosition().x, tile->getPosition().y);
            bugCircleMap[bug->getId()] = bugCircle;
        }
    }


    void BoardDisplay::updateBoardDisplay()
    {
        gameWindow->clear();

        for (const auto tile: boardTiles) {
            gameWindow->draw(*tile);
        }

        for (const auto &bug: boardBugs)
        {
            if (bug->getIsAlive())
            {
                auto pos = bug->getPosition();
                const auto tile = boardMap[pos.toString()];
                bugCircleMap[bug->getId()]->setPosition(tile->getPosition().x, tile->getPosition().y);
                gameWindow->draw(*bugCircleMap[bug->getId()]);
            }
        }

        gameWindow->display();
    }




} // graphics