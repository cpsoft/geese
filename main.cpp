#include <stdio.h>
#include <stdlib.h>
#include "ui_manager.h"
#include "window.h"

int main(int argc, char* argv[]){
	Window* window;
	UIManager* ptr;

	if (argc < 2){
		printf ("usage: %s <xul file>\n", argv[0]);
		return -1;
	}
	ptr = new UIManager();
	ptr->open(argv[1]);
	ptr->layout();

	window = new Window(argc, argv);

	window->setSize(800, 600);
	window->setTitle("test");
	window->run();

	ptr->cleanLayout();
	delete ptr;
	delete window;
	return 0;
}
	
