/**
 * \file Branch.h
 *
 * \author Becky Henning
 *
 * Branch tree part
 */

#pragma once

#include "TreePart.h"
#include "PseudoRandom.h"

#include <vector>
#include <memory>

class CTreeObject;

 /**
 * Class that represents a branch
 */
class CBranch : public CTreePart
{
public:

	/// Draw the tree part
	virtual void Draw(Gdiplus::Graphics* graphics, double parentAngle, Gdiplus::Point pos) override;

	/// Grow the tree part
	virtual void Grow(CPseudoRandom* random) override;

	/// Harvest fruit from tree parts
	void Harvest();

	/// Set the depth
	/// \param depth
	void SetDepth(int depth) { mDepth = depth; }

	/// Set the tree
	/// \param tree the tree
	void SetTree(CTreeObject* tree) { mTree = tree; }

private:
	/// Depth
	int mDepth = 1;

	/// Width of branch
	double mWidth = 1.5;

	/// Length of branch
	double mLength = 5.5;

	/// Vector of tree parts
	std::vector<std::shared_ptr<CTreePart>> mTreeParts;

	/// Tree
	CTreeObject* mTree = nullptr;

	/// Children
	std::vector<std::shared_ptr<CBranch>> mBranches;
};

