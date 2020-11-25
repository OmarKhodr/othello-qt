#include "redchip.h"

/**
 * @brief redchip::redchip, contructor for red chip
 * @file redchip.h
 * creates the chip that the RED player can place on the grid
 */
redchip::redchip()
{
    setPixmap((QPixmap(":/imagesOthello/redChip90by90.png")).scaled(90, 90));

}
