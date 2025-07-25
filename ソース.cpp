#include <iostream>

#ifdef DEBUG

#include <stdio.h>// some enveronet. are you know kbhit().

#else

#include <conio.h>

#endif // DEBUG

#ifdef DEBUG
//#else
int kbhit() {
	// Simulate kbhit for demonstration purposes
	// In a real application, this would check if a key has been pressed
	return 0; // No key pressed
}
int getch() {
	// Simulate getch for demonstration purposes
	// In a real application, this would return the pressed key
	return 0; // No key pressed
}
int key() {
	// Simulate key input for demonstration purposes
	// In a real application, this would return the pressed key
	return 0; // No key pressed
}
int getkey() {
	// Simulate getkey for demonstration purposes
	// In a real application, this would return the pressed key
	return 0; // No key pressed
}
#endif

//#define realtime

#ifdef realtime
int key() {
	if(_kbhit()) {
		return _getch(); // Return the pressed key
	}

	return 0; // No key pressed
}
#else
int key() {
		return _getch(); // Return the pressed key
}
#endif // realtime

// for main flow taskers. who coll me my old task.
// this is  my lost technique.
// recaver my old task.

// why geforce needs searface.
// i use this archtechtuer.
// bigest and biggest.
// it crasy.so it crash me.
//but formal.
//so formal. cry.

//we computer evolution is ender.
//sorcer is complete.
//your ‹ï is complitely opend.
//what are you doing?
//we need next step.

const int width = 10;
const int height = 10;

int x = 0;
int y = 0;

void initialize() {
	// Initialize x and y to some values
	x = 5;
	y = 10;
}

void reset() {
	// Reset x and y to zero
	x = 0;
	y = 0;
}

void move() {
	// Move x and y by some values

	int k = key();

	if (k == 'a') {
		x--;
	}
	if (k == 'd') {
		x++;
	}
	if (k == 'w') {
		y--;
	}
	if (k == 's') {
		y++;
	}
	if (k == 'r') {
		reset(); // Reset x and y if 'r' is pressed
	}
	if (k == 'i') {
		initialize(); // Initialize x and y if 'i' is pressed
	}
	if (k == 'q') {
		std::cout << "Exiting..." << std::endl;
		exit(0); // Exit the program if 'q' is pressed
	}
	if (k == ' ') {
		std::cout << "Space key pressed. Current position: (" << x << ", " << y << ")" << std::endl;
	}
}

void character(char C) {
	// Display a character at the current position
	std::cout << "\033[2J\033[1;1H"; // Clear the console and move cursor to top-left
	//std::cout << "\033[<" << y << ">; <" << x << ">H"; // Move cursor to (x, y)
	//std::cout.flush();
	//std::cout << /*"Character at (" << x << ", " << y << "): " <<*/ C << std::endl;
	//std::cout.flush();

	std::cout <<"\033[<"<<y+1<<">; <"<<x+1<<">H" << std::endl;
	std::cout << C << std::endl;
	//std::cout.flush();
	std::cout << "\033[1;1H"; // Move cursor to the top-left corner
	//std::cout.flush();

}

void clearScreen() {
	// Clear the console screen
	std::cout << "\033[2J\033[1;1H"; // Clear the console and move cursor to top-left
	//std::cout.flush();
}

void display(char C) {

	//clear the console screen
	std::cout << "\033[2J\033[1;1H"; // Clear the console and move cursor to top-left

	// Display the current values of x and y
	for(int i = 0; i < width; ++i) {
		std::cout << C;
	}
	std::cout << std::endl;
	for(int j = 0; j < height; ++j) {
		std::cout << C;
		for (int i = 1; i < width; ++i) {//width - 1 is the last column. this is the first column.
#ifdef DEBUG
			std::cout << " ";

#else
			std::cout << "x";
#endif // DEBUG


		}
		std::cout << C;
		std::cout << std::endl;
	}
	for(int i = 0; i < width; ++i) {
		std::cout << C;
	}

	std::cout << std::endl;

	//std::cout << "x: " << x << ", y: " << y << std::endl;
}

int isquit() {
	// Check if the user wants to quit
	if (key() == 'q') {
		std::cout << "Exiting..." << std::endl;
		return 1; // Return 1 to indicate exit
	}
	return 0; // Return 0 to continue
}

void clear() {
	// Clear the console screen



	//std::cout << "\033[2J\033[1;1H"; // Clear the console and move cursor to top-left
	//std::cout.flush();
}

void clamp() {
	// Clamp x and y to the boundaries of the console
	if (x < 0) {
		x = 0;
	}
	if (x >= width) {
		x = width - 1;
	}
	if (y < 0) {
		y = 0;
	}
	if (y >= height) {
		y = height - 1;
	}	
}

int main() {
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Width: " << width << ", Height: " << height << std::endl;
	
	// Simple loop to demonstrate x and y increment
	for (int i = 0; i < 5; ++i) {
		x += 1;
		y += 2;
		std::cout << "x: " << x << ", y: " << y << std::endl;
	}

	initialize(); // Initialize x and y
	reset(); // Reset x and y
	_getch(); // Wait for a key press to continue
	clearScreen(); // Clear the console screen
	_getch();//why you mix cryant and server.
	//_getch();//–³


	do {
		display('*'); // Display the initial state
		std::cout << "x:" << x << ", y:" << y << std::endl;
		move(); // Move based on key input
		clamp(); // Clamp x and y to the boundaries
		character('Y'); // Display a character at the current position
	} while (!isquit());
	return 0;
}	