#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::loadMap(std::string _filepath)
{
    std::string line;
    std::ifstream levelFile;
    levelFile.open("ExampleMaps/" + _filepath);

    if (!levelFile.is_open()) return;

    int y = 0;
    map* newMap = new map;

    while (!levelFile.eof())
    {
        std::getline(levelFile, line);

        if (line.empty()) continue;

        Node* prevNode = nullptr;

        for (int x = 0; x < int(line.length()); ++x)
        {
            char actorChar = line[x];
            Node* newNode = new Node;
            newNode->setPos(x, y);
            if (prevNode != nullptr)
            {
                newNode->setLeft(prevNode);
                prevNode->setRight(newNode);
            }

            if (y > 0)
            {
                Node* topNode = newMap->nodes[x*(y-1)];
                newNode->setUp(topNode);
                if (topNode->getLeft() != nullptr)
                {
                    newNode->setUpLeft(topNode->getLeft());
                    topNode->getLeft()->setDownRight(newNode);
                }

                if (topNode->getRight() != nullptr)
                {
                    newNode->setUpRight(topNode->getRight());
                    topNode->getRight()->setDownLeft(newNode);
                }
            }

            switch (actorChar)
            {
            // wall
            case 'w':
                newNode->setTileType(WALL);
                break;
                
            // clear
            case '.':
                newNode->setTileType(CLEAR);
                break;

            // start
            case 's':
                newNode->setTileType(ENTRANCE);
                newMap->entranceCount++;
                break;

            // destination
            case 'x':
                newNode->setTileType(EXIT);
                newMap->exitCount++;
                break;

            default:
                newNode->setTileType(ITEM);
                newMap->itemCount++;
                break;
            }

            prevNode = newNode;
            newMap->nodes.push_back(newNode);
        }
        y++;
    }

    levels.push_back(newMap);

    levelFile.close();

    std::cout << "Map Loaded Successfully" << std::endl;
}

void Graph::printMap(int _index)
{
    if (_index < 0 || _index > levels.size())
    {
        std::cout << "index out of range" << std::endl;
        return;
    }
    map level = *levels[_index];

    if (level.entranceCount > 1 || level.exitCount > 1)
    {
        std::cout << "Invalid Map" << std::endl;
    }

    int x = 0;
    int y = 0;

    for (int i = 0; i < level.nodes.size(); ++i)
    {
        int items = 0;
        char printChar = '.';

        switch (level.nodes[i]->getTileType())
        {
        case CLEAR:
            printChar = '.';
            break;

        case ENTRANCE:
            printChar = 's';
            break;

        case EXIT:
            printChar = 'x';
            break;

        case WALL:
            printChar = 'w';
            break;

        case ITEM:
            printChar = 97+items++;
            break;
        }

        if (level.nodes[i]->getPos().y > y)
        {
            ++y;
            std::cout << std::endl;
        }
        std::cout << printChar;
    }

}

void Graph::unload(int _index)
{
    for (int i = 0; i < levels[_index]->nodes.size(); ++i)
    {
        delete levels[_index]->nodes[i];
    }
    levels[_index]->nodes.clear();
}

Node* Graph::createNode(NodeType _type)
{
    Node* newNode = new Node;
    newNode->setTileType(_type);
    return newNode;
}
