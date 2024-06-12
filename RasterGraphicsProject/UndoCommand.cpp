#include "UndoCommand.h"

void UndoCommand::undo() const
{
	execute();
}
