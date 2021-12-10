#include "PainterFrame.h"
#include "frame.h"
#include <iostream>
#include <exception>
Frame* mainWindow = nullptr;
int main() {
	try {
		mainWindow = new PainterFrame(L"±×¸²ÆÇ", 1000,800);
		mainWindow->init();
		mainWindow->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
