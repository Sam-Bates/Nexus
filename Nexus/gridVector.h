#ifndef gridVector_h_
#define gridVector_h_
#include <vector>

void initVector();
void fillRandomPlaces();
void removeFreeVecSpot(int);
void removeFreeVecSpot(int, int);
int numberOfFreeBlocks();
void delLines();
void addBall(int, int);
void addNewBall(int, int);
void removeBall(int, int);
//void addFreeSpotToVector(int, int);
extern std::vector<int> freePlacesVec;
//extern int freePlacesArr [100];
#endif