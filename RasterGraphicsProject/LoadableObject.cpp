#include "LoadableObject.h"

void LoadableObject::save()
{
	if(!isLoaded)
		loadData();
	saveData();
}
