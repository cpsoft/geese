#include <stdio.h>
#include <stdlib.h>
#include "ui_manager.h"

int main(int argc, char* argv[]){
	UIManager* ptr;

	if (argc < 2){
		printf ("usage: %s <xul file>\n", argv[0]);
		return -1;
	}
	ptr = new UIManager();
	ptr->open(argv[1]);
	ptr->layout();
	delete ptr;
	return 0;
}
	
