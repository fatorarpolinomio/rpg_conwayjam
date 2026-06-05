#include <cstdlib>
#include "raylib.h"
#include <iostream>
#include "interno/protagonista/protagonista.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

int main() {

	
	InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"RPG");

	Protagonista violeta(Vector2{20,20});

	while (!WindowShouldClose())
	{
		
		violeta.Update();
		

		BeginDrawing();
			ClearBackground(WHITE);
			
			violeta.Draw();
		EndDrawing();
	}
	
	std::cout << "teste";

	CloseWindow();
	return 0;
}