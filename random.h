//
// Created by Fenrisúlfr on 16/11/2022.
//

#ifndef CADAVRE_EXQUIS_RANDOM_H
#define CADAVRE_EXQUIS_RANDOM_H

#define STATE_VECTOR_LENGTH 624
#define STATE_VECTOR_M      397 /* changes to STATE_VECTOR_LENGTH also require changes to this */

typedef struct tagMTRand {
    unsigned long mt[STATE_VECTOR_LENGTH];
    int index;
} MTRand;

MTRand seedRand(unsigned long seed);
unsigned long genRandLong(MTRand* rand);
double genRand(MTRand* rand);
int g_rand(int cap);

#endif //CADAVRE_EXQUIS_RANDOM_H
