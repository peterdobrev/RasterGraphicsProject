#include <iostream>
#include "Application.h"
#include "String.h"
#include "CommandFactory.h"
#include <sstream>
#include "TransformableImageFactory.h"

void Application::printSession() const
{
    activeSession->print();
}

void Application::handleSwitchSession()
{
}

void Application::addCommand(PolymorphicPtr<Command>& command)
{
    activeSession->commands.pushBack(command);
}

void Application::popBackCommand()
{
    activeSession->commands.popBack();
}

void Application::switchSession(Session* other)
{
}

PolymorphicPtr<Command> Application::parseCommand()
{
    PolymorphicPtr<Command> command;

    String commandType;
    std::cin >> commandType;

    if (commandType == "undo")
    {
        popBackCommand();
    }
    else if (commandType == "session")// "session info"
    {
        printSession();
    }
    else if (commandType == "switch")
    {
        handleSwitchSession();
    }
    else
    {
        command = CommandFactory::createCommand(commandType);
    }

    return command;
}

void Application::run()
{
    Vector<PolymorphicPtr<TransformableImage>> images = getLoadImages();
    Vector<PolymorphicPtr<Command>> commands;
    Session* session = new Session(images, commands);
    activeSession = session;
    session = nullptr;
}

void Application::readCommand()
{
    PolymorphicPtr<Command> command = parseCommand();
    if (command.get() != nullptr)
    {
        addCommand(command);
    }
}

const Session& Application::getSession() const
{
    return *activeSession;
}

Vector<PolymorphicPtr<TransformableImage>> Application::getLoadImages() const
{
    char buffer[1024];
    while (true)
    {
        std::cin.getline(buffer, sizeof(buffer), '\n');
        std::stringstream ss(buffer);
        String loadCommand;
        ss >> loadCommand;
        if (loadCommand == "load")
        {
            return TransformableImageFactory::createImagesFromStringstream(ss);
        }
    }
}
