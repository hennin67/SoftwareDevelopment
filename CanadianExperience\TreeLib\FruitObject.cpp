/**
* \file FruitObject.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "FruitObject.h"
#include "TreeObject.h"

using namespace std;

/**
* Constructor
* \param tree the tree
*/
CFruitObject::CFruitObject(CTreeObject* tree) : CTreePartDrawable(tree, tree->GetOrange())
{
}

/**
* Draw the fruit in the basket
* \param graphics The graphics object to draw on
* \param x X location of the basket
* \param y Y location of the basket
*/
void CFruitObject::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
	CTreePartDrawable::Draw(graphics, GetAngle(), Gdiplus::Point(mX+x,mY+y));
}
