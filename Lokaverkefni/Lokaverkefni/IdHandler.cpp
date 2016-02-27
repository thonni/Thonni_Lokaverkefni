#include "IdHandler.h"



IdHandler::IdHandler()
{
	currentId = 0;
}

int IdHandler::getId()
{
	id = currentId;

	currentId = currentId + 1;

	return id;
}