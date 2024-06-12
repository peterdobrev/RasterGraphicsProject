#include "Application.h"
int main()
{
	Application::getInstance().run();
	while (true)
	{
		Application::getInstance().readCommand();
	}
}