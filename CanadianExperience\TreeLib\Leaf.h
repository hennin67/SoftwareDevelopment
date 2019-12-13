/**
 * \file Leaf.h
 *
 * \author Becky Henning
 *
 * Leaf Tree Part
 */

#pragma once

#include "TreePartDrawable.h"

#include <string>

class CTreeObject;

/**
* Class that represents a leaf
*/
class CLeaf : public CTreePartDrawable
{
public:
	/// Constructor
	CLeaf(CTreeObject* tree);

	/// Destructor
	virtual ~CLeaf() {};
};

