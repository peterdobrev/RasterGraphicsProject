#pragma once
#include "Session.h"
class Application
{
public:
	void run();
	void readCommand();
	const Session& getSession() const;
	static Application& getInstance()
	{
		static Application app;
		return app;
	}

private:
	Session* activeSession = nullptr;

	Application() = default;

	Vector<PolymorphicPtr<TransformableImage>> getLoadImages() const;
	void printSession() const;
	void handleSwitchSession();
	void addCommand(PolymorphicPtr<Command>& command);
	void popBackCommand();
	void switchSession(Session* other);
	PolymorphicPtr<Command> parseCommand();

};

