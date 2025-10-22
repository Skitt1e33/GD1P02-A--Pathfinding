#include "Graph.h"

void Graph::loadMap()
{
    unload();

    currentLevel = _filePath;

    actors = new std::vector<Actor*>;

    std::string line;
    std::ifstream levelFile;
    levelFile.open("Levels/" + _filePath);

    if (!levelFile.is_open()) return;

    int y = 0;

    while (!levelFile.eof())
    {
        std::getline(levelFile, line);

        if (line.empty()) continue;

        for (int x = 0; x < int(line.length()); ++x)
        {
            char actorChar = line[x];

            if (actorChar != 'o' && actorChar != 'm') { actors->push_back(createActor(actorChar, x, y)); }
            else if (actorChar == 'm')
            {
                // Sets moving platform to move between spawn point and next recorded 'm' character location
                MovingPlatform* newPlat = new MovingPlatform(x * 30, 0);
                newPlat->setPosition(sf::Vector2f(x * 30, y * 30));
                actorChar = line[++x];
                while (actorChar != 'm')
                {
                    actorChar = line[++x];
                }
                newPlat->setEnd(x * 30);
                actors->push_back(newPlat);
            }
        }
        y++;
    }

    levelFile.close();

    for (int i = 0; i < actors->size() - 1; ++i)
    {
        if (actors->at(i)->getClassType() == ENEMY)
        {
            dynamic_cast<Enemy*>(actors->at(i))->setPlayer(player);
        }
    }

    cam->setFocus(player);

    loaded = true;
}
