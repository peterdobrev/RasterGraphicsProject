#pragma once
#include "Session.h"
class Application
{
public:
	void run();
	void readCommand();
	const Session& getSession() const;

private:
	Session* activeSession = nullptr;

	Application() = default;

	void printSession() const;
	void handleSwitchSession();
	void addCommand(PolymorphicPtr<Command>& command);
	void popBackCommand();
	void switchSession(Session* other);
	PolymorphicPtr<Command> parseCommand();

};

