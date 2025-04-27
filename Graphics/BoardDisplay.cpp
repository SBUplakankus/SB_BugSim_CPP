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

        // Adjust cell size based on vector size and display size
        const int cellWidth = (displayWidth - menuWidth) / (gridWidth + 1);
        const int cellHeight = displayHeight / (gridHeight + 1);
        int counter = 0;

        for (int i = 0; i <= gridWidth; i++)
        {
            for (int j = 0; j <= gridHeight; j++)
            {
                Position pos(i, j);
                auto tile = new RectangleShape(Vector2f(cellWidth, cellHeight));

                // Make every second tile a different colour
                tile->setFillColor(counter % 2 == 0 ? boardColor1 : boardColor2);
                tile->setPosition(Vector2f(i * cellWidth, j * cellHeight));

                // Add to board map used for positioning and tile vector used for rendering
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

        // Render all the board tiles
        for (const auto &tile: boardTiles)
        {
            gameWindow->draw(*tile);
        }

        // Render all the bug circles
        updateBoardDisplay();

        gameWindow->display();

        // While the window is open, update the game on space pressed
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
            // Get the bugs positioning and find the tile for that position in the map
            auto pos = bug->getPosition();
            const auto tile = boardMap[pos.toString()];

            // Scale the circle to fit inside the tile
            auto* bugCircle = new CircleShape(tile->getSize().x / 2);

            // Set bug colour based on bug type
            if (bug->getBugType() == "Crawler")
            {
                bugCircle->setFillColor(crawlerColor);
            }
            else if (bug->getBugType() == "Hopper")
            {
                bugCircle->setFillColor(hopperColor);
            }
            else if (bug->getBugType() == "Drinker")
            {
                bugCircle->setFillColor(drinkerColor);
            }

            // Set the position of the bug to be inside the tile and add the bug to the map
            bugCircle->setPosition(tile->getPosition().x, tile->getPosition().y);
            bugCircleMap[bug->getId()] = bugCircle;
        }
    }


    void BoardDisplay::updateBoardDisplay()
    {
        gameWindow->clear();

        for (const auto tile: boardTiles)
        {
            gameWindow->draw(*tile);
        }

        for (const auto &bug: boardBugs)
        {
            // If the bug is alive, update its position to the latest one in the simulation
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