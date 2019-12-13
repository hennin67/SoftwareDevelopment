/**
 * \file TreePartDrawable.h
 *
 * \author Becky Henning
 *
 * Tree part drawable
 */

#pragma once
#include "TreePart.h"
#include "PseudoRandom.h"
#include "TreeImage.h"

#include <string>
#include <memory>

class CFruitObject;
class CTreeObject;

 /**
 * Class that represents a tree part drawable
 */
class CTreePartDrawable : public CTreePart
{
public:
	/// Constructor
	CTreePartDrawable(CTreeObject* tree, std::shared_ptr<CTreeImage> image);

	/// Draw the tree part
	virtual void Draw(Gdiplus::Graphics* graphics, double parentAngle, Gdiplus::Point pos) override;

	/// Grow the tree part
	virtual void Grow(CPseudoRandom* random) override;

private:
	/// The image for this drawable
	std::shared_ptr<CTreeImage> mImage;

	/// scale of image
	double mScale = 0.1;
};

