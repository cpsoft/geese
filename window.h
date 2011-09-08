#ifndef __WINDOW_H__
#define __WINDOW_H__

class Window{
private:
	unsigned int _width;
	unsigned int _height;
	char* _title;

public:
	Window(int argc, char* argv[]);
	~Window();

	void setSize(int w, int h);
	void setTitle(char* title);
	void run();
};

#endif
