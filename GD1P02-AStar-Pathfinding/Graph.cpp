#include "Graph.h"

void Graph::loadMap(std::string _filepath)
{
    std::string line;
    std::ifstream levelFile;
    levelFile.open("ExampleMaps/" + _filepath);

    if (!levelFile.is_open()) return;

    int y = 0;

    while (!levelFile.eof())
    {
        std::getline(levelFile, line);

        if (line.empty()) continue;

        for (int x = 0; x < int(line.length()); ++x)
        {
            char actorChar = line[x];

            switch (actorChar)
            {
            // wall
            case 'w':

                break;
                
            // clear
            case '.':

                break;

            // start
            case 's':

                break;

            // destination
            case 'x':

                break;
            }
        }
        y++;
    }

    levelFile.close();
}

void Graph::unload(int _index)
{
    for (int i = 0; i < levels[_index].nodes.size(); ++i)
    {
        delete levels[_index].nodes[i];
    }
    levels[_index].nodes.clear();
}

Node* Graph::createNode(NodeType _type)
{
    Node* newNode = new Node;
    newNode->setTileType(_type);
    return newNode;
}
