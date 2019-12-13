/**
 * \file FruitObject.h
 *
 * \author Becky Henning
 *
 * Fruit Object
 */

#pragma once

#include "Fruit.h"
#include "TreePartDrawable.h"

class CTreeObject;

/**
 * Class that represents a fruit.
 *
 * Changed as needed for Tree Demo
 */
class CFruitObject : public CFruit, public CTreePartDrawable
{
public:
	/// Constructor
	CFruitObject(CTreeObject* tree);

	/// Destructor
	virtual ~CFruitObject() {}

	/// Set the position of the fruit in the basket
	/// \param x the x location
	/// \param y the y location
	virtual void SetBasketPosition(int x, int y) { mX = x, mY = y; }

	/// Draw the fruit in the basket
	virtual void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y);

	/// Harvest the tree part
	/// \return the fruit object
	virtual CFruitObject* PickFruit() override { return this; }

private:
	/// the x location
	int mX;

	/// the y location
	int mY;
};

