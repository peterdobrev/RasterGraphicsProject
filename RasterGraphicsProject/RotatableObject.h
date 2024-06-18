#pragma once
class RotatableObject
{
public:
	virtual void rotateLeft();
	virtual void rotateRight();
	virtual void applyRotation() = 0;

	virtual RotatableObject* clone() const = 0;

	virtual ~RotatableObject() = default;

protected:
	enum Direction : char {
		top,
		left,
		bottom,
		right
	};

	Direction direction = Direction::top;

};

