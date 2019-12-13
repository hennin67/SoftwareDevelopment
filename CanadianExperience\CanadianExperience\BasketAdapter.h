/**
 * \file BasketAdapter.h
 *
 * \author Becky Henning
 *
 * Basket adapter for Tree Lib
 */

#pragma once

#include "Drawable.h"
#include "TreeAdapter.h"
#include "Basket.h"
#include "Timeline.h"

#include <vector>
#include <memory>

 /**
  * Class for basket in drawings
  */
class CBasketAdapter : public CDrawable
{
public:
	/// Constructor
	CBasketAdapter(const std::wstring& name);

	/// Destructor
	virtual ~CBasketAdapter() {};

	/** Draw the basket
	 * \param graphics Graphics object to draw on */
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/// Set the timeline
	void SetTimeline(CTimeline* timeline);

	/** Test to see if we have been clicked on by the mouse
	 * \param pos Position to test
	 * \return true if clicked on */
	virtual bool HitTest(Gdiplus::Point pos) { return false; }

	/// Add a tree to vector
	/// \param tree a tree
	void AddTree(std::shared_ptr<CTreeAdapter> tree) { mTrees.push_back(tree); }

	/// Set harvest frame
	/// \param harvest
	void SetHarvest(int harvest) { mFrameHarvest = harvest; }

	/// Get harvest frame
	/// \return mFrameHarvest
	int GetHarvest() { return mFrameHarvest; }

	/// Set empty frame
	/// \param empty
	void SetEmpty(int empty) { mFrameEmpty = empty; }

	/// Get Empty frame
	/// \return mFrameEmpty
	int GetEmpty() { return mFrameEmpty; }

private:
	/// the trees
	std::vector<std::shared_ptr<CTreeAdapter>> mTrees;

	/// the basket
	std::shared_ptr<CBasket> mBasket;

	/// the empty frame
	int mFrameEmpty = 300;

	/// the harvest frame
	int mFrameHarvest = 250;

	/// timeline
	CTimeline* mTimeline = nullptr;
};

