#pragma once
class IdHandler
{
private:
	int currentId;          //The id that it gives out next

	int id;                 //Temporarily holds the id;

public:
	IdHandler();            //Constructor

	int getId();            //Returns the next id and adds one to the next
};

