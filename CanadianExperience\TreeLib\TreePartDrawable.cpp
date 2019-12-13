/**
* \file TreePartDrawable.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "TreePartDrawable.h"
#include "TreeObject.h"
#include "TreeImage.h"

using namespace std;
using namespace Gdiplus;

/** Constructor
 * \param tree the tree
 * \param image the drawable image
*/
CTreePartDrawable::CTreePartDrawable(CTreeObject* tree, shared_ptr<CTreeImage> image)
{
	mImage = image;
}

/**
 * Draw the drawable
 * \param graphics Graphics context to draw on
 * \param parentAngle the angle of the parent
 * \param pos the position of the drawable
 */
void CTreePartDrawable::Draw(Gdiplus::Graphics* graphics, double parentAngle, Gdiplus::Point pos)
{
	mImage->Draw(graphics, GetAngle(), mScale, pos.X, pos.Y);
}

/**
 * Draw the drawable
 * \param rnd the random object
 */
void CTreePartDrawable::Grow(CPseudoRandom* rnd)
{
	double growRate = 1.003;

	mScale *= growRate;
}
