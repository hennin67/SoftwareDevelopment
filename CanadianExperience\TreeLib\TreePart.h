/**
 * \file TreePart.h
 *
 * \author Becky Henning
 *
 * Base class for Tree Parts
 */

#pragma once

#include "PseudoRandom.h"

class CFruitObject;

/**
* Class that represents a tree part.
*/
class CTreePart
{
public:
	/// Constructor
	CTreePart() {}

	/// Destructor
	virtual ~CTreePart() {}

	/// Draw the tree part
	/// \param graphics Gdiplus graphics
	/// \param parentAngle the parent's angle
	/// \param pos the position of the tree part
	virtual void Draw(Gdiplus::Graphics* graphics, double parentAngle, Gdiplus::Point pos) {}

	/// Grow the tree part
	/// \param rnd random object
	virtual void Grow(CPseudoRandom* rnd) {};

	/// Harvest the tree part
	/// \return nullptr
	virtual CFruitObject* PickFruit() { return nullptr; }

	/// Set the position of the tree object
	/// \param position the position to set
	void SetPosition(Gdiplus::Point position) { mPosition = position; }

	/// Get the position of the tree object
	/// \return mPosition
	Gdiplus::Point GetPosition() { return mPosition; }

	/// Get growth scale
	/// \return mGrowthScale
	double GetGrowth() { return mGrowthScale; }

	/// Get the delta
	/// \return mDelta
	double GetDelta() { return mDelta; }

	/// Set the tree part angle
	/// \param angle the angle
	void SetAngle(double angle) { mAngle = angle; }

	/// Get the tree part angle
	/// \return mAngle
	double GetAngle() { return mAngle; }

private:
	/// Angle of part
	double mAngle = (3 * 3.14159) / 2;

	/// max growth of tree part
	double mGrowthScale = 0.35;

	/// amount to grow tree part by
	double mDelta = 0.03;

	/// depth of tree part
	int mDepth = 0;

	/// Position of tree object
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
};

