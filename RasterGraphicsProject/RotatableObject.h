#pragma once
class RotatableObject
{
	virtual void rotateLeft();
	virtual void rotateRight();

protected:
	enum Direction {
		top,
		left,
		bottom,
		right
	};

	Direction direction = Direction::top;

	virtual void applyRotation() = 0;
};

