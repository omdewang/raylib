#include "raylib.h"
#include <stdio.h>

const int screenwidth = 800;
const int screenheight = 450;

int main(int argc, char *argv[])
{
  InitWindow(screenwidth,screenheight,"My First Window");

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
