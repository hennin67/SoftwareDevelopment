/**
 * \file TreeObject.h
 *
 * \author Becky Henning
 *
 * Tree Object 
 */

#pragma once

#include "Tree.h"
#include "TreeImage.h"
#include "PseudoRandom.h"

#include <vector>
#include <memory>
#include <string>

class CBranch;

 /**
  * Class that represents a tree.
  *
  * Changed as needed for Tree Demo
  */
class CTreeObject : public CTree
{
public:
	/// Constructor
	CTreeObject();

	/// Destructor
	virtual ~CTreeObject() {}

	/// Copy constructor disabled
	CTreeObject(const CTreeObject&) = delete;

	/// Assignment operator disabled
	void operator=(const CTreeObject&) = delete;

	/// Set the position for the root of the tree
	virtual void SetRootLocation(int x, int y) override;

	/// Draw the tree at the currently specified location
	virtual void DrawTree(Gdiplus::Graphics* graphics) override;

	/// Set the current tree frame
	virtual void SetTreeFrame(int frame) override;

	/// Reset the frame
	void Reset();

	/// Set the tree seed
	virtual void SetSeed(int seed) override;

	/// Harvest all of the fruit
	virtual std::vector<std::shared_ptr<CFruit>> Harvest() override;

	/// Adds fruit to tree list
	/// \param fruit the fruit to add to the list
	void AddFruit(std::shared_ptr<CFruit> fruit) { mFruit.push_back(fruit); }

	/// Return orange
	/// \return mOrangeImage
	std::shared_ptr<CTreeImage> GetOrange() { return mOrangeImage; }

	/// Return leaf
	/// \return mLeafImage
	std::shared_ptr<CTreeImage> GetLeaf() { return mLeafImage; }

	/// Get the wind speed
	/// \return mWindSpeed
	double GetWindSpeed() { return mWindSpeed; }

	/// Set  the wind speed
	/// \param speed Wind speed in miles per hour
	virtual void SetWindSpeed(double speed) { mWindSpeed = speed; }

private:
	/// Seed
	int mSeed = 450;

	/// Current frame
	int mFrame = 0;

	/// Wind speed affecting tree
	double mWindSpeed = 0;

	/// The root branch
	std::shared_ptr<CBranch> mRoot = nullptr;

	/// List of fruit on tree
	std::vector<std::shared_ptr<CFruit>> mFruit;

	/// Orange image
	std::shared_ptr<CTreeImage> mOrangeImage;

	/// Leaf image
	std::shared_ptr<CTreeImage> mLeafImage;

	/// Random
	CPseudoRandom mRandom;
};

