#include "ComponentMovable.hpp"

bool componentMovable::getAbleToMove() const
{
    return this->_ableToMove;
}

void componentMovable::setAbleToMove(bool ableToMove) {
    this->_ableToMove = ableToMove;
}