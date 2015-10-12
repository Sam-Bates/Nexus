#ifndef gridVector_h_
#define gridVector_h_
#include <vector>

void initVector();
void fillRandomPlaces();
void removeFreeVecSpot(int);
void removeFreeVecSpot(int, int);
void delLines();
void changeBall(int, int, int);

//void addFreeSpotToVector(int, int);
extern std::vector<int> freePlacesVec;
//extern int freePlacesArr [100];
#endif