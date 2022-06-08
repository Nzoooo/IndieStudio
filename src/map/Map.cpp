/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** Map
*/

#include "Map.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

Map::Map()
{
    this->_map = new int *[MAPSIZE];
    for (size_t i = 0; i < MAPSIZE; i++) {
        this->_map[i] = new int[MAPSIZE];
        for (size_t j = 0; j < MAPSIZE; j++) {
            if (j == 0 || j == MAPSIZE - 1 || i == 0 || i == MAPSIZE - 1 || (i % 2 == 0 && j % 2 == 0))
                this->_map[i][j] = 1;
            else
                this->_map[i][j] = 0;
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
    for (size_t i = 0; i < MAPSIZE; i++) {
        for (size_t j = 0; j < MAPSIZE; j++) {
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
    } while ((random.first == -lastDirection.first && random.second == -lastDirection.second) || (random.first == lastDirection.first && random.second == lastDirection.second));
    return (random);
}

void Map::putSpawn()
{
    this->_map[1][1] = 0;
    this->_map[1][2] = 0;
    this->_map[2][1] = 0;
    this->_map[1][MAPSIZE - 2] = 0;
    this->_map[1][MAPSIZE - 3] = 0;
    this->_map[2][MAPSIZE - 2] = 0;
    this->_map[MAPSIZE - 2][1] = 0;
    this->_map[MAPSIZE - 2][2] = 0;
    this->_map[MAPSIZE - 3][1] = 0;
    this->_map[MAPSIZE - 2][MAPSIZE - 2] = 0;
    this->_map[MAPSIZE - 2][MAPSIZE - 3] = 0;
    this->_map[MAPSIZE - 3][MAPSIZE - 2] = 0;
}

void Map::generateMap()
{
    std::srand(std::time(nullptr));
    int maxTunnels = MAXTUNNELS;
    size_t currentRow = std::floor(std::rand() % MAPSIZE);
    size_t currentColumn = std::floor(std::rand() % MAPSIZE);
    while (currentRow < 1 && currentColumn < 1) {
        currentRow = std::floor(std::rand() % MAPSIZE);
        currentColumn = std::floor(std::rand() % MAPSIZE);
    }
    std::pair<int, int> lastdirection = {0, 0};
    lastdirection = randomDirection(lastdirection);
    size_t randomLength = std::ceil(std::rand() % MAXLENGHT);
    size_t tunnelLength = 0;
    while (1) {
        printf("tunel lenght = %ld, tunel max = %d\n", tunnelLength, maxTunnels);
        if (((currentRow == 0) && (lastdirection.first == -1)) || ((currentColumn == 0) && (lastdirection.second == -1)) || ((currentRow == MAPSIZE - 1) && (lastdirection.first == 1))
            || ((currentColumn == MAPSIZE - 1) && (lastdirection.second == 1)) || this->_map[currentRow][currentColumn] == 1) {
            lastdirection = randomDirection(lastdirection);
            currentRow += lastdirection.first;
            currentColumn += lastdirection.second;
        } else {
            this->_map[currentRow][currentColumn] = 2;
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
        if (currentRow >= MAPSIZE || currentRow <= 0)
            currentRow = std::floor(std::rand() % MAPSIZE);
        if (currentColumn >= MAPSIZE || currentColumn <= 0)
            currentColumn = std::floor(std::rand() % MAPSIZE);
        if (maxTunnels == 0) {
            break;
        }
    }
    putSpawn();
}
