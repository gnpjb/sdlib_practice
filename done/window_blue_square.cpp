#include<stdio.h>
#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<fstream>

#define fps 60
#define default_window_width 400
#define default_window_height 400

//recordar usar siempre std:: para el std library

class sprite {
	
	private:
		SDL_Surface* image = NULL;
		SDL_Rect rect;
		int origin_x, origin_y;
		
	public:
		
		sprite(Uint32 color, int x, int y, int w = 48, int h = 64){
			image = SDL_CreateRGBSurface(0,w,h,32,0,0,0,0);
			SDL_FillRect( image, NULL, color );
			
			rect=image->clip_rect;
			
			origin_x=default_window_width/2;
			origin_y=default_window_height/2;
			
			rect.x = x-origin_x;
			rect.y = y-origin_y;
			
		}
		void update(){
			//nothing still
		}
		void draw(SDL_Surface *destination){
			SDL_BlitSurface( image, NULL, destination, &rect);
			
			
		}
		
		
		
};



int main(int argc,char* args[]){
    
	
	//initialize SDL, if it failed then inform error and close
	std::cout<<"initializing"<<std::endl;
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        std::cout<<"error initializing"<<std::endl<<SDL_GetError()<<std::endl;
        return 1;
    }
    
    const char* title="random title";// create a title variable for the window
    SDL_Window* window=NULL;				//create window pointer
    window=SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			default_window_width,
			default_window_height,
			SDL_WINDOW_RESIZABLE);//initialize the window and if it fails get error and close program
	if( window==NULL ){
		std::cout<<"error creating window"<<std::endl<<SDL_GetError();
		SDL_Quit();
		return 1;
	}
	
	
	//create surface variable and error handle if fail
	SDL_Surface* surface=NULL;
	surface=SDL_GetWindowSurface(window);
	if( surface==NULL ){
		std::cout<<"failed to get surface"<<std::endl<< SDL_GetError()<<std::endl;
		return 1;
	}
	
	
	//create color variable and fill the surface
	Uint32 color=SDL_MapRGB( (*surface).format, 200,200,200 );
	SDL_FillRect(surface,NULL,color);
	SDL_UpdateWindowSurface(window);
	Uint32 color_rect=SDL_MapRGB( (*surface).format, 0,0,200 );
	
	//create a sprite
	sprite image_sprite( color_rect, default_window_width/2, default_window_height/2 );
	image_sprite.draw( surface );
	SDL_UpdateWindowSurface(window);
	
	//  create event variables
    SDL_Event event;
    bool repeat=true;
	Uint32 starting_tick;
	
// 	while loop for event polling
	while(repeat){
		
		starting_tick = SDL_GetTicks();//for fps handling
		
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				repeat=false;
				break;
			}
		}
		
		
		if((1000/fps) > (SDL_GetTicks()- starting_tick)){//caping framerate
			SDL_Delay((1000/fps) - (SDL_GetTicks()- starting_tick));
		}
	}

	
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
