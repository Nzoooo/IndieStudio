/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    this->_map = new int *[MAP_SIZE];
    for (std::size_t i = 0; i < MAP_SIZE; i++) {
        this->_map[i] = new int[MAP_SIZE];
        for (std::size_t j = 0; j < MAP_SIZE; j++) {
            if (j == 0 || j == MAP_SIZE - 1 || i == 0 || i == MAP_SIZE - 1 || (i % 2 == 0 && j % 2 == 0))
                this->_map[i][j] = WALL;
            else
                this->_map[i][j] = AIR;
        }
    }
}

Map::~Map()
{
}

int **Map::getMap()
{
    return (this->_map);
}

void Map::readMap()
{
    for (std::size_t i = 0; i < MAP_SIZE; i++) {
        for (std::size_t j = 0; j < MAP_SIZE; j++) {
            std::cout << this->_map[i][j];
        }
        std::cout << std::endl;
    }
}

std::pair<int, int> Map::randomDirection(std::pair<int, int> lastDirection)
{
    std::array<std::pair<int, int>, 4> directions = {{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

    int nbRand = 0;
    std::pair<int, int> random;
    do {
        nbRand = std::floor(std::rand() % 4);
        random = directions[nbRand];
    } while ((random.first == -lastDirection.first && random.second == -lastDirection.second)
        || (random.first == lastDirection.first && random.second == lastDirection.second));
    return (random);
}

void Map::putSpawn()
{
    this->_map[1][1] = AIR;
    this->_map[1][2] = AIR;
    this->_map[2][1] = AIR;
    this->_map[1][MAP_SIZE - 2] = AIR;
    this->_map[1][MAP_SIZE - 3] = AIR;
    this->_map[2][MAP_SIZE - 2] = AIR;
    this->_map[MAP_SIZE - 2][1] = AIR;
    this->_map[MAP_SIZE - 2][2] = AIR;
    this->_map[MAP_SIZE - 3][1] = AIR;
    this->_map[MAP_SIZE - 2][MAP_SIZE - 2] = AIR;
    this->_map[MAP_SIZE - 2][MAP_SIZE - 3] = AIR;
    this->_map[MAP_SIZE - 3][MAP_SIZE - 2] = AIR;
}

void Map::generateMap()
{
    std::srand(std::time(nullptr));
    int maxTunnels = MAXTUNNELS;
    std::size_t currentRow = std::floor(std::rand() % MAP_SIZE);
    std::size_t currentColumn = std::floor(std::rand() % MAP_SIZE);
    while (currentRow < 1 && currentColumn < 1) {
        currentRow = std::floor(std::rand() % MAP_SIZE);
        currentColumn = std::floor(std::rand() % MAP_SIZE);
    }
    std::pair<int, int> lastdirection = {0, 0};
    lastdirection = randomDirection(lastdirection);
    std::size_t randomLength = std::ceil(std::rand() % MAXLENGHT);
    std::size_t tunnelLength = 0;
    while (1) {
        if (((currentRow == 0) && (lastdirection.first == -1)) || ((currentColumn == 0) && (lastdirection.second == -1))
            || ((currentRow == MAP_SIZE - 1) && (lastdirection.first == 1)) || ((currentColumn == MAP_SIZE - 1) && (lastdirection.second == 1))
            || this->_map[currentRow][currentColumn] == 1) {
            lastdirection = randomDirection(lastdirection);
            currentRow += lastdirection.first;
            currentColumn += lastdirection.second;
        } else {
            this->_map[currentRow][currentColumn] = BOX;
            lastdirection = randomDirection(lastdirection);
            currentRow += lastdirection.first;
            currentColumn += lastdirection.second;
            tunnelLength++;
        }
        if (tunnelLength >= randomLength) {
            randomLength = std::ceil(std::rand() % MAXLENGHT);
            tunnelLength = 0;
            lastdirection = randomDirection(lastdirection);
            maxTunnels--;
        }
        if (currentRow >= MAP_SIZE || currentRow <= 0)
            currentRow = std::floor(std::rand() % MAP_SIZE);
        if (currentColumn >= MAP_SIZE || currentColumn <= 0)
            currentColumn = std::floor(std::rand() % MAP_SIZE);
        if (maxTunnels == 0) {
            break;
        }
    }
    putSpawn();
}
