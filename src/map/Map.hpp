/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <array>
#include <iostream>

#define MAPSIZE    15
#define MAXTUNNELS 55
#define MAXLENGHT  30

class Map {
  public:
    Map();
    ~Map();

    int **initMap();

    int **getMap();

    void readMap();

    void generateMap();
    void putSpawn();
    void randomBonus(size_t currentRow, size_t currentColumn);
    std::pair<int, int> randomDirection(std::pair<int, int> lastDirection);

  private:
    int **_map;
};

#endif /* !MAP_HPP_ */
