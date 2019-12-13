/**
 * \file TreeAdapter.cpp
 *
 * \author Becky Henning
 */

#include "pch.h"

#include "TreeAdapter.h"
#include "TreeFactory.h"
#include "TreeSeedDlg.h"

#include "Tree.h"
#include "Fruit.h"

#include <memory>
#include <vector>

/** Constructer
* \param name The filename */
CTreeAdapter::CTreeAdapter(const std::wstring& name) : CDrawable(name)
{
	CTreeFactory factory;
	mTree = factory.CreateTree();
}

/** Draw the basket
* \param graphics Graphics object to draw on */
void CTreeAdapter::Draw(Gdiplus::Graphics* graphics)
{
	mFrame = mTimeline->GetCurrentFrame();
	if (mFrame >= mStart)
	{
		/// GROW
		mTree->SetRootLocation(0, 0);
		mTree->SetTreeFrame((int)mFrame-(int)mStart);

		float scale = 0.3f;

		auto save = graphics->Save();
		graphics->TranslateTransform((float)mPlacedPosition.X,
			(float)mPlacedPosition.Y);
		graphics->ScaleTransform(scale, scale);
		mTree->DrawTree(graphics);
		graphics->Restore(save);
	}

}

/** Set the timeline
*   \param timeline - the item we need */
void CTreeAdapter::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline);
	mTimeline = timeline;
}

/** Harvest the fruit
*   \return fruit vector */
std::vector<std::shared_ptr<CFruit>> CTreeAdapter::Harvest()
{
	return mTree->Harvest();
}

/**
* Seed the tree
*/
void CTreeAdapter::SeedDlg()
{
	CTreeSeedDlg dlg(mTree);
	dlg.DoModal();
}