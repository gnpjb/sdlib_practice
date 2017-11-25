#include<stdio.h>
#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<fstream>

//recordar usar siempre std:: para el std library

bool BasicCreateWindow(SDL_Window *window,const char* title){
	window=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1000,700,SDL_WINDOW_RESIZABLE);
}

void CloseAll(SDL_Window* window){
	SDL_DestroyWindow(window);
	SDL_Quit();
}


int main(int argc,char* args[]){
    
	
// 	initialize SDL, if it failed then inform error and close
	std::cout<<"initializing"<<std::endl;
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        std::cout<<"error initializing"<<std::endl<<SDL_GetError()<<std::endl;
        return 1;
    }
    
    const char* title="random title";// create a title variable for the window
    SDL_Window* window;				//create window pointer
    BasicCreateWindow(window,title);//initialize the window and if it fails get error and close program
	if( window==NULL )
	{
		std::cout<<"error creating window"<<std::endl<<SDL_GetError();
		SDL_Quit();
		return 1;
	}
    
//  create event variable and start while loop for event polling
    SDL_Event event;
    bool repeat=true;
	while(repeat){
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				repeat=false;
				break;
			}
		}
	}
	
	CloseAll(window);
	return 0;
}
