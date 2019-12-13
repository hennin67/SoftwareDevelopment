/**
* \file TreeObject.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "TreeObject.h"
#include "Branch.h"
#include "PseudoRandom.h"

using namespace Gdiplus;
using namespace std;

/// Leaf image name
const wstring LeafImage = L"images/leaf.png";

/// orange image name
const wstring OrangeImage = L"images/orange.png";

/**
* Constructor
*/
CTreeObject::CTreeObject()
{
	mRoot = make_shared<CBranch>();
	mLeafImage = make_shared<CTreeImage>(LeafImage);
	mOrangeImage = make_shared<CTreeImage>(OrangeImage);
}

/**
* Set the position for the root of the tree
* \param x X location (pixels)
* \param y Y location (pixels)
*/
void CTreeObject::SetRootLocation(int x, int y)
{
	if (mRoot != nullptr)
	{
		mRoot->SetPosition(Point(x, y));
		mRoot->SetTree(this);
		mRandom.Seed(mSeed);
	}
}

/**
* Draw the tree at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CTreeObject::DrawTree(Gdiplus::Graphics* graphics)
{	
	if (mRoot != nullptr)
	{
		mRoot->Draw(graphics, 0, mRoot->GetPosition());
	}
}

/**
* Set the current tree frame
* \param frame Frame number
*/
void CTreeObject::SetTreeFrame(int frame)
{
	if (frame < mFrame)
	{
		Reset();
	}

	while (mFrame < frame) 
	{
		mFrame++;
		mRoot->Grow(&mRandom);
	}
}

/**
* Reset the tree
*/
void CTreeObject::Reset()
{
	mFrame = 0;
	Gdiplus::Point pos = mRoot->GetPosition();
	mRoot = make_shared<CBranch>();
	SetRootLocation(pos.X, pos.Y);
	SetSeed(mSeed);
	mFruit.clear();
}

/**
* Set the tree seed
* \param seed An integer number. Each number makes a different tree
*/
void CTreeObject::SetSeed(int seed)
{
	mSeed = seed;
	mRandom.Seed(seed);
}

/**
 * Harvest all of the fruit
 * \return Vector of objects of type CFruit
 */
std::vector<std::shared_ptr<CFruit>> CTreeObject::Harvest()
{
	mRoot->Harvest();
	std::vector<std::shared_ptr<CFruit>> temp = mFruit;
	mFruit.clear();
	return temp;
}
