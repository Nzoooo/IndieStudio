/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(size_t dimension, size_t maxTunnels, size_t maxLength): _dimensions(dimension), _maxTunnels(maxTunnels), _maxLength(maxLength)
{
    this->_map = new int*[MAPSIZE];
    for (size_t i = 0; i < MAPSIZE; i++) { 
        this->_map[i] = new int[MAPSIZE];
        for (size_t j = 0; j < MAPSIZE; j++) {  
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