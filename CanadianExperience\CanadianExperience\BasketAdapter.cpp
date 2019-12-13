/**
 * \file BasketAdapter.cpp
 *
 * \author Becky Henning
 */

#include "pch.h"
#include "BasketAdapter.h"
#include "TreeFactory.h"

 /** Constructer
 * \param name The filename */
CBasketAdapter::CBasketAdapter(const std::wstring& name) : CDrawable(name)
{
	CTreeFactory factory;
	mBasket = factory.CreateBasket();
}

/** Draw the tree
* \param graphics Graphics object to draw on */
void CBasketAdapter::Draw(Gdiplus::Graphics* graphics)
{
	mBasket->SetBasketLocation(0,0);
	double frame = mTimeline->GetCurrentFrame();

	if (frame >= mFrameHarvest && frame < mFrameHarvest+30)
	{
		for (auto tree : mTrees)
		{
			mBasket->AddToBasket(tree->Harvest());
		}
	}

	if (frame >= mFrameEmpty)
	{
		mBasket->EmptyBasket();
	}

	float scale = 0.3f;

	auto save = graphics->Save();
	graphics->TranslateTransform((float)mPlacedPosition.X,
		(float)mPlacedPosition.Y);
	graphics->ScaleTransform(scale, scale);
	mBasket->DrawBasket(graphics);
	graphics->Restore(save);
}

/** Set the timeline
*   \param timeline - the item we need */
void CBasketAdapter::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline);
	mTimeline = timeline;
}
