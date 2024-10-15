#include <iostream>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <cstdio>

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
    /*
    for(int i = 0; i < 255; i++) {
        SDL_FillRect( winSurface, nullptr, SDL_MapRGB( winSurface->format, i, 255-i, i%2*i) );
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
     */



    //next test of rendering shapes
    //While application is running

    int SCREEN_WIDTH, SCREEN_HEIGHT;
    SCREEN_HEIGHT = 720;
    SCREEN_WIDTH = 1280;
    bool quit = false;
    bool success=false;
    SDL_Event e;
    SDL_Renderer* gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    //Create window
    SDL_Window* gWindow = SDL_CreateWindow( "Seggs", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create renderer for window
        gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
        if( gRenderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderCopy(gRenderer, nullptr, nullptr, nullptr);
        }
    }
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        //SDL_RenderClear( gRenderer );

        //Render texture to screen
        //SDL_RenderCopy( gRenderer, nullptr, NULL, NULL );

        //Update screen
        SDL_RenderPresent( gRenderer );
    }
    // Destroy the window. This will also destroy the surface
    SDL_DestroyWindow( window );

    // Quit SDL
    SDL_Quit();

    // End the program
    return 0;
}