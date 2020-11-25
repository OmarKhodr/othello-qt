#include "greenplus.h"

/**
 * @brief greenplus::greenplus
 * @file greenplus.h
 * Creates the green plus picture that signals a correct positision for a player to place a chip.
 */
greenplus::greenplus()
{
    setPixmap((QPixmap(":/imagesOthello/greenPlus90by90.png")).scaled(75, 75));

}
