#include "FixedTimestepTutorialApp.h"

int main() {
	
	// allocation
	auto app = new FixedTimestepTutorialApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}