#ifndef graphics_h_
#define graphics_h_
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#include <string>



bool init();
bool loadMedia();
void close();
void drawRect(int, int, int);

const int MAGNIFICATION = 32;

SDL_Texture* loadTexture(std::string path);

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* tTurquoise;
extern SDL_Texture* tBlue;
extern SDL_Texture* tFree;
extern SDL_Texture* tGreen;
extern SDL_Texture* tPurple;
extern SDL_Texture* tRed;
extern SDL_Texture* tSelected;
extern SDL_Texture* tYellow;

#endif