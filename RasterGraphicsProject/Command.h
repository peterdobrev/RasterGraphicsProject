#pragma once
class Command
{
	virtual void execute() const = 0;
	~Command() = default;
};

