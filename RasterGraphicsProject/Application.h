#pragma once
#include "Session.h"
#include "Command.h"

class Application
{
public:
	void run();
	
	static Application& getInstance();

private:
	bool isRunning = false;
	int activeSession = -1;
	Vector<PolymorphicPtr<Session>> sessions;

	Application() = default;

	void readCommand();
	void load();
	void switchSession();
	void help() const;
	void close();
	void exit();

	Vector<PolymorphicPtr<TransformableImage>> getLoadImages() const;
	PolymorphicPtr<Command> parseCommand();

	void deloadImagesFromCurrentSession();
};

