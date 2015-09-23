#ifndef graphics_h_
#define graphics_h_
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#include <string>
#include <SDL.h>


bool init();
bool loadMedia();
void close();
void drawRect(int, int, int);

const int MAGNIFICATION = 32;

SDL_Texture* loadTexture(std::string path);


#endif