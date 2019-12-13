/**
* \file Leaf.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "Leaf.h"
#include "TreeObject.h"

using namespace std;


/** 
* Constructor
* \param tree the tree
*/
CLeaf::CLeaf(CTreeObject* tree) : CTreePartDrawable(tree, tree->GetLeaf())
{
}
