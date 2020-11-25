#include "bluechip.h"

/**
 * @brief blueChip::blueChip, constructor for the blue chips
 * @file bluechip.h
 * creates the chip that the BLUE player can place on the grid
 */
blueChip::blueChip()
{
    setPixmap((QPixmap(":/imagesOthello/blueChip90by90.png")).scaled(90, 90));

}
