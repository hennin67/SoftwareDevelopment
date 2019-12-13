/**
 * \file TreeImage.h
 *
 * \author Becky Henning
 *
 * Tree Image Class
 */

#pragma once

#include <memory>
#include <string>


/**
 * Class that represents an image used by our system.
 */
class CTreeImage
{
public:
	/// Constructor
	CTreeImage(const std::wstring name);

	/// Destructor
	virtual ~CTreeImage() {}

	/// Default constructor/disabled
	CTreeImage() = delete;

	/// Copy constructor/disabled
	CTreeImage(const CTreeImage&) = delete;

	/// Draw the image
	void CTreeImage::Draw(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y);

private:
	/// pointer to the image
	std::shared_ptr<Gdiplus::Bitmap> mImage;

};

