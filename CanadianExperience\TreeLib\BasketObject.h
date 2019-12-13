/**
 * \file BasketObject.h
 *
 * \author Becky Henning
 *
 * Basket Object
 */

#pragma once

#include "Basket.h"
#include "TreeImage.h"
#include "PseudoRandom.h"
#include "Fruit.h"

#include <memory>

/**
* Class that represents a basket
*/
class CBasketObject : public CBasket
{
public:
	/// Constructor
	CBasketObject();

	/// Destructor
	virtual ~CBasketObject() {};

	/**
	* Set the position for the basket.
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	virtual void SetBasketLocation(int x, int y) override { mX = x, mY = y; };

	/**
	* Draw the basket at the currently specified location
	*/
	virtual void DrawBasket(Gdiplus::Graphics* graphics) override;

	/**
	 * Add fruit to the basket
	 */
	virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit) override;

	/**
	 * Empty all fruit from the basket
	 */
	virtual void EmptyBasket() override;

private:
	/// The image of the basket
	std::shared_ptr<CTreeImage> mBasketImage1;

	/// The image of the front of the basket
	std::shared_ptr<CTreeImage> mBasketImage2;

	/// The image of the fruit
	std::shared_ptr<CTreeImage> mFruitImage;

	/// X position
	int mX;

	/// Y position
	int mY;

	/// Random
	CPseudoRandom mRandom;

	/// Fruit in basket
	std::vector < std::shared_ptr<CFruit>> mFruit;
};

