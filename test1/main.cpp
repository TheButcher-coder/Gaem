#include <iostream>
#include <chrono>
#include <thread>
#include <SDL.h>

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

void sleep(int millis) {
    this_thread::sleep_for(chrono::milliseconds(millis));
}

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {

    // Pointers to our window and surface
    SDL_Surface* winSurface = NULL;
    SDL_Window* window = NULL;

    // Initialize SDL. SDL_Init will return -1 if it fails.
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
        //system("pause");
        // End the program
        return 1;
    }

    // Create our window
    window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN );

    // Make sure creating the window succeeded
    if ( !window ) {
        cout << "Error creating window: " << SDL_GetError()  << endl;
        //system("pause");
        // End the program
        return 1;
    }

    // Get the surface from the window
    winSurface = SDL_GetWindowSurface( window );

    // Make sure getting the surface succeeded
    if ( !winSurface ) {
        cout << "Error getting surface: " << SDL_GetError() << endl;
        //system("pause");
        // End the program
        return 1;
    }

    // Fill the window with a white rectangle
    for(int i = 0; i < 255; i++) {
        SDL_FillRect( winSurface, nullptr, SDL_MapRGB( winSurface->format, i, 255-i, 0) );
        SDL_Event e;
        bool running=true;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }
        // Update the window display
        sleep(10);
        SDL_UpdateWindowSurface( window );
    }


    // Wait
    //system("pause");
    bool running = true;
    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
                break;

            }
        }
    }
    // Destroy the window. This will also destroy the surface
    SDL_DestroyWindow( window );

    // Quit SDL
    SDL_Quit();

    // End the program
    return 0;
}