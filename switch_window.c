#include "raylib.h"

int screenwidth = 800;
int screenheight = 450;

typedef enum gamescreen { LOGO, TITLE, GAMEPLAY, ENDING } gamescreen;

int main(void) {

  gamescreen currentscreen = LOGO;
  int framescounter = 0;

  InitWindow(screenwidth, screenheight, "Changing Screen");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    switch (currentscreen) {

    case LOGO: {
      framescounter++;
      if (framescounter > 600) {
        currentscreen = TITLE;
      }
    } break;
    case TITLE: {
      if (IsGestureDetected(GESTURE_TAP) || IsKeyPressed(KEY_ENTER)) {
        currentscreen = GAMEPLAY;
      }
    } break;
    case GAMEPLAY: {
      if (IsGestureDetected(GESTURE_TAP) || IsKeyPressed(KEY_ENTER)) {
        currentscreen = ENDING;
      }
    } break;
    case ENDING: {
      if (IsGestureDetected(GESTURE_TAP) || IsKeyPressed(KEY_ENTER)) {
        currentscreen = TITLE;
      }
    } break;
    default: break;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);
        switch(currentscreen){
            case LOGO:
                {
                    DrawText("LOGO Screen",20,20,40,LIGHTGRAY);
                    DrawText("Wait for 10 seconds",(screenwidth/2)-125,(screenheight/2),20,LIGHTGRAY);
                }
            break;
            case TITLE:
                {
                    DrawRectangle(0,0,screenwidth,screenheight,YELLOW);
                    DrawText("TITLE Screen",20,20,40,ORANGE);
                    DrawText("Press Enter or Tap to Jump to GAMEPLAY",(screenwidth/2)-200,(screenheight/2),20,ORANGE);
                }
            break;
            case GAMEPLAY:
                {
                    DrawRectangle(0,0,screenwidth,screenheight,LIME);
                    DrawText("GAMEPLAY",20,20,40,GREEN);
                    DrawText("Press Enter or Tap to Jump to ENDING",(screenwidth/2)-200,(screenheight/2),20,GREEN);
                }
            break;
            case ENDING:    
                {
                    DrawRectangle(0,0,screenwidth,screenheight,SKYBLUE);
                    DrawText("ENDING",20,20,40,BLUE);
                    DrawText("Press Enter or Tap to Jump to TITLE",(screenwidth/2)-200,(screenheight/2),20,BLUE);
                }
            default:
                break;
        }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
