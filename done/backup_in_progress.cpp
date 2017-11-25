#include<stdio.h>
#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<fstream>

//recordar usar siempre std:: para el std library

SDL_Window* gwindow=NULL;
SDL_Surface* gscreensurface=NULL;
SDL_Surface* gimage=NULL;
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gwindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gwindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gscreensurface = SDL_GetWindowSurface( gwindow );
        }
    }

    return success;

}

bool loadMedia(std::string filename)
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gimage = SDL_LoadBMP( filename.c_str());
    if( gimage == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n",filename.c_str(), SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gimage );
    gimage = NULL;

    //Destroy window
    SDL_DestroyWindow( gwindow );
    gwindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}


int main(int argc,char* args[])
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia("random.bmp") )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gimage, NULL, gscreensurface, NULL );
            //Update the surface
            SDL_UpdateWindowSurface( gwindow ); //Wait two seconds
            SDL_Delay( 2000 );
        }
    }
    //main loop flag
    bool quit=false;
    
    //event handler
    SDL_Event e;
    
    //while app is running
    while(!quit)
    {
        //handle events on queue
        while(SDL_PollEvent(&e)=!0)
        {
            if(e.type==SDL_Quit)
            {
                quit=true;
            }
        }
        //Apply the image
                SDL_BlitSurface( gXOut, NULL, gscreensurface, NULL );
            
                //Update the surface
                SDL_UpdateWindowSurface( gwindow );
    }
    

    //Free resources and close SDL
    close();

    return 0;
        
}
