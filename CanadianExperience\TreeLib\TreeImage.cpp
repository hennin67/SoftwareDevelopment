/**
* \file TreeImage.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "TreeImage.h"

using namespace std;
using namespace Gdiplus;

/// Radians to Degrees
double RtoD = 57.2958;

/**
 * Constructor
 * \param name the filename
 */
CTreeImage::CTreeImage(const std::wstring name)
{
	mImage = shared_ptr<Bitmap>(Bitmap::FromFile(name.c_str()));
}

/**
* Draw the image
* \param graphics The graphics object to draw on
* \param angle the angle of the image
* \param scale the scale of the image
* \param x X location of the image
* \param y Y location of the image
*/
void CTreeImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->RotateTransform((float)(angle * RtoD));
	graphics->ScaleTransform((float)scale, (float)scale);
	graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2,
		-(int)mImage->GetHeight(),
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}
