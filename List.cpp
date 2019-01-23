/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (What other characteristic does our List have?)
 *
 * Author:Jiaqing Hu
 * Date:2019/01/20
 */

#include "List.h"

// Default constructor
// This will create default list with both 0 elementCount & MAX_ELEMENT capacity
List::List()
{
	this->elementCount = 0;
	this->capacity = MAX_ELEMENTS;
}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const
{
	return this->elementCount;
}



// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement) {
	if (search(newElement))
		return false;
	else if (this->elementCount>=this->capacity)
	{
		return false;
	}
	else
	{
		elements[elementCount] = newElement;
		this->elementCount++;
		return true;

	}
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved) {
	if (this->elementCount==0||search(toBeRemoved)==NULL)
		return false;
	else
	{
	for (int i = 0; i < this->elementCount; i++)
		{
			if (toBeRemoved.getCareCard()==this->elements[i].getCareCard())
			{
				for (int j = i; j <this->elementCount; j++)
				{
					this->elements[j] = this->elements[j + 1];
				}
			}
		}
		this->elementCount--;
	}
	return true;
}

// Description: Remove all elements.
void List::removeAll() {
	if(this->elementCount == 0)
		return;
	else
	{
		for (int i = 0; i < this->elementCount; i++)
		{
			Patient temp;
			this->elements[i]=temp;
		}
		this->elementCount = 0;
	}
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) {
	Patient* p = this->elements;
	for (int i = 0; i < this->elementCount; p++)
		if (this->elements[i] == target)
			return p;
	return NULL;
}

// Description: Return the element at index i
Patient List::getElements(int i) const
{
	return this->elements[i];
}

	// Description: Modify element at index with target
void List::modifyElement(const Patient& target,const int index){
	this->elements[index] = target;
}