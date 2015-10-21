#ifndef gridVector_h_
#define gridVector_h_
#include <vector>
#include "board.h"

void initVector();
void fillRandomPlaces();
void removeFreeVecSpot(int);
void removeFreeVecSpot(int, int);
void delLines();
void changeBall(int, int, int);

//void addFreeSpotToVector(int, int);
//extern std::vector<int> freePlacesVec;
extern std::vector<int> freePlacesVec;// setting the size of the vector to be the total size of the board

//extern int freePlacesArr [100];
#endif