#pragma once
class LoadableObject
{
public:
	virtual void save();
	virtual void loadData() = 0;
	virtual void saveData() = 0;
	virtual void clearData() = 0;
	virtual LoadableObject* clone() const = 0;
	virtual ~LoadableObject() = default;

protected:
	bool isLoaded = false;
};

