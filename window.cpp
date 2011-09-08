#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>

#include <vg/openvg.h>
#include <vg/vgu.h>
#include "window.h"

Window::Window(int argc, char* argv[]){
	_width = 800;
	_height = 600;
	_title = NULL;
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA |
                      GLUT_STENCIL | GLUT_MULTISAMPLE);
#if 0 	

  glutReshapeFunc(testReshape);
  glutDisplayFunc(testDisplay);
  glutIdleFunc(testAnimate);
  glutKeyboardFunc(testKeyboard);
  glutSpecialFunc(testSpecialKeyboard);
  glutMouseFunc(testButton);
  glutMotionFunc(testDrag);
  glutPassiveMotionFunc(testMove);
  atexit(testCleanup);
#endif
}

Window::~Window(){
	if (NULL != _title){
		free(_title);
	}
}

void Window::setSize(int w, int h){
	_width = w;
	_height = h;

	glutInitWindowPosition(0,0);
	glutInitWindowSize(w,h);
	//vgCreateContextSH(w,h);
}

void Window::setTitle(char* title){
	if (NULL == title){
		return;
	}
	_title = strdup(title);
	glutCreateWindow(title);
}

void Window::run(){
	glutMainLoop();
}
