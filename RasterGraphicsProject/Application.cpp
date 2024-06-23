#include "Application.h"

#include <iostream>
#include <sstream>

#include "String.h"

#include "TransformableImageFactory.h"
#include "CommandFactory.h"

#include "Transformation.h"


Application& Application::getInstance()
{
    static Application app;
    return app;
}

void Application::run()
{
    if (isRunning)
    {
        return;
    }

    isRunning = true;
    while (isRunning)
    {
        std::cout << "> ";

        try {
            readCommand();
        }

        //catch (std::exception e)
        //{
            //std::cout << e.what();
        }

        std::cout << std::endl;
    }
}

void Application::readCommand()
{
    PolymorphicPtr<Command> commandPtr = parseCommand();
    if (commandPtr.get())
    {
        commandPtr.get()->execute();
        commandPtr.get()->printFeedback();
    }
}

PolymorphicPtr<Command> Application::parseCommand()
{
    PolymorphicPtr<Command> command;

    String commandType;
    std::cin >> commandType;

    if (commandType == "load")
    {
        load();
    }
    else if (commandType == "switch")
    {
        switchSession();
    }
    else if (commandType == "undo")
    {
        undo();
    }
    else if (commandType == "help")
    {
        help();
    }
    else if (commandType == "close")
    {
        close();
    }
    else if (commandType == "exit")
    {
        exit();
    }
    else if(activeSession >= 0) // if there is an active session
    {
        command = std::move(CommandFactory::createCommand(commandType, sessions[activeSession].get()));

        if (!command.get())
        {
            std::cerr << "Command not recognized! See \'help\' for list of commands!";
        }
    }
    else
    {
        std::cerr << "No active session! See \'help\' for list of commands!";
    }

    return command;
}

void Application::deloadImagesFromCurrentSession()
{
    size_t length = sessions[activeSession].get()->getImagesCount();
    for (size_t i = 0; i < length; i++)
    {
        sessions[activeSession].get()->getImageAtIndex(i).get()->clearData();
    }
}


void Application::load()
{
    Vector<PolymorphicPtr<TransformableImage>> images = getLoadImages();
    Vector<PolymorphicPtr<Transformation>> transformations;
    Session* session = new Session(images, transformations);
    
    activeSession = sessions.getSize();
    sessions.pushBack(session);
    
    session = nullptr;
    
    std::cout << "Created session: " << activeSession << "\nLoaded: ";

    size_t length = images.getSize();
    for (size_t i = 0; i < length; i++)
    {
        std::cout << "\"" << images[i].get()->getName() << "\" ";
    }
}

void Application::switchSession()
{
    int id;
    std::cin >> id;

    if (id >= 0 && id < sessions.getSize())
    {
        deloadImagesFromCurrentSession();
        activeSession = id;
        std::cout << "Switched to session " << activeSession;
    }
    else
    {
        throw std::exception("No such session exists!");
    }
}

void Application::undo()
{
    size_t lastTransformationIndex = sessions[activeSession]->getTransformationsCount() - 1;
    sessions[activeSession]->getTransformationAtIndex(lastTransformationIndex)->undo();
    std::cout << "Undo last command!";
}

void Application::help() const
{
    std::cout << "Available commands:\n";

    std::cout << "1. load <filename> [<filename2> ...]\n";
    std::cout << "   Description: Loads the specified image files and starts a new session.\n";
    std::cout << "   Example: load image1.ppm\n\n";

    std::cout << "2. add <image>\n";
    std::cout << "   Description: Adds the specified image to the current session.\n";
    std::cout << "   Example: add image2.pgm\n\n";

    std::cout << "3. close\n";
    std::cout << "   Description: Closes the current session without saving any changes.\n\n";

    std::cout << "4. save\n";
    std::cout << "   Description: Saves all images in the current session after applying all pending transformations.\n\n";

    std::cout << "5. saveas <newfilename>\n";
    std::cout << "   Description: Saves the first loaded image in the session under a new name after applying all pending transformations.\n";
    std::cout << "   Example: saveas newimage.ppm\n\n";

    std::cout << "6. greyscale\n";
    std::cout << "   Description: Converts all color images in the current session to grayscale.\n\n";

    std::cout << "7. monochrome\n";
    std::cout << "   Description: Converts all images in the current session to monochrome (black and white).\n\n";

    std::cout << "8. negative\n";
    std::cout << "   Description: Applies a negative transformation to all images in the current session.\n\n";

    std::cout << "9. rotate <direction>\n";
    std::cout << "   Description: Rotates all images in the current session 90 degrees in the specified direction (left or right).\n";
    std::cout << "   Example: rotate left\n\n";

    std::cout << "10. undo\n";
    std::cout << "    Description: Undoes the last transformation applied in the current session.\n\n";

    std::cout << "11. session info\n";
    std::cout << "    Description: Displays information about the current session, including session ID, loaded images, and pending transformations.\n\n";

    std::cout << "12. switch <session>\n";
    std::cout << "    Description: Switches to the session with the specified session ID.\n";
    std::cout << "    Example: switch 2\n\n";

    std::cout << "13. collage <direction> <image1> <image2> <outimage>\n";
    std::cout << "    Description: Creates a collage from the two specified images in the specified direction (horizontal or vertical) and saves it as a new image.\n";
    std::cout << "    Example: collage horizontal image1.ppm image2.ppm collage.ppm\n\n";

    std::cout << "14. help\n";
    std::cout << "    Description: Displays this help message.\n\n";

    std::cout << "15. exit\n";
    std::cout << "    Description: Exits the application.\n\n";
}

void Application::close()
{
    if (activeSession >= 0)
    {
        activeSession = -1;
        std::cout << "Closed active session!";
    }
    else
    {
        std::cerr << "No active session! Create session first! See \'help\' for list of commands!";
    }
}

void Application::exit()
{
    close();
    std::cout << "\nExiting...";
    isRunning = false;
}

Vector<PolymorphicPtr<TransformableImage>> Application::getLoadImages() const
{
    char buffer[1024];
    std::cin.getline(buffer, sizeof(buffer), '\n');
    std::stringstream ss(buffer);
    return TransformableImageFactory::createImagesFromStringstream(ss);
}