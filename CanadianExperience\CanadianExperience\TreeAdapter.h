/**
 * \file TreeAdapter.h
 *
 * \author Becky Henning
 *
 * Tree adapter for Tree Lib
 */

#pragma once

#include "Drawable.h"
#include "Tree.h"
#include "Timeline.h"

#include <memory>

class CBasketAdapter;


 /**
  * Class for tree in drawings
  */
class CTreeAdapter : public CDrawable
{
public:
	/// Constructor
	CTreeAdapter(const std::wstring& name);

	/// Destructor
	virtual ~CTreeAdapter() {};

	/// Draw the basket
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/** Test to see if we have been clicked on by the mouse
	 * \param pos Position to test
	 * \return true if clicked on */
	virtual bool HitTest(Gdiplus::Point pos) { return false; }

	/// Set the timeline
	virtual void SetTimeline(CTimeline* timeline);

	/// Return the frame
	/// \return mFrame
	double GetFrame() { return mFrame; }

	/// Harvest the fruit
	std::vector<std::shared_ptr<CFruit>> Harvest();

	/// Seed the dlg box
	void SeedDlg();

	/// Start of tree growth
	/// \param start the start frame
	void SetGrow(int start) { mStart = start; }

	/// Get start of growth
	/// \return mStart
	int GetGrow() { return mStart; }

private:
	/// the tree
	std::shared_ptr<CTree> mTree = nullptr;

	/// start of growth
	int mStart = 0;

	/// current frame
	double mFrame = 0;

	/// timeline
	CTimeline* mTimeline = nullptr;
};

