
OBJS=in_progress.cpp

OBJ_NAME=in_progress

all:$(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
hello_world_sdl: hello_world_sdl.cpp
	g++ hello_world_sdl.cpp -w -lSDL2 -o hello_world_sdl
create_file:
	touch in_progress_new.cpp
	echo "#include<stdio.h>">> in_progress_new.cpp
	echo "#include<SDL2/SDL.h>">> in_progress_new.cpp
	echo "#include<iostream>">> in_progress_new.cpp
	echo "#include<string>">> in_progress_new.cpp
	echo "#include<fstream>">> in_progress_new.cpp
	echo "">> in_progress_new.cpp
	echo "//recordar usar siempre std:: para el std library">> in_progress_new.cpp
	echo "">> in_progress_new.cpp
	echo "int main(int argc,char* args[])">> in_progress_new.cpp
	echo "{">> in_progress_new.cpp
	echo "">> in_progress_new.cpp
	echo "}">> in_progress_new.cpp
	
