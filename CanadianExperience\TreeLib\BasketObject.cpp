/**
* \file BasketObject.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "BasketObject.h"

using namespace std;

/// The image of the entire basket
const std::wstring BasketImage = L"images/basket.png";

/// The image for the front only of the basket
const std::wstring BasketFrontImage = L"images/basket-front.png";

/**
 * Constructor
 */
CBasketObject::CBasketObject()
{
	mBasketImage1 = make_shared<CTreeImage>(BasketImage);
	mBasketImage2 = make_shared<CTreeImage>(BasketFrontImage);

	mRandom.Seed((int)time(nullptr));
}

/**
* Draw the fruit in the basket
* \param graphics The graphics object to draw on
*/
void CBasketObject::DrawBasket(Gdiplus::Graphics* graphics)
{
	mBasketImage1->Draw(graphics, 0, 1, mX, mY);
	mBasketImage2->Draw(graphics, 0, 1, mX, mY);

	for (auto item : mFruit)
	{
		item->DrawInBasket(graphics, mX, mY-75);
	}
}

/**
 * Add fruit to the basket
 * \param fruit Vector of fruit objects
 */
void CBasketObject::AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit)
{
	for (auto item : fruit)
	{
		item->SetBasketPosition(mRandom.Random(-40,40), mRandom.Random(-20,10));
		mFruit.push_back(item);
	}
}

/**
* Empty all fruit from the basket
*/
void CBasketObject::EmptyBasket()
{
	mFruit.clear();
}

