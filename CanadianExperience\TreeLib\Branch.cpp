/**
* \file Branch.cpp
*
* \author Becky Henning
*/

#include "pch.h"
#include "Branch.h"
#include "FruitObject.h"
#include "TreeObject.h"
#include "PseudoRandom.h"
#include "Leaf.h"

#include <algorithm>

using namespace std;
using namespace Gdiplus;

/**
* Draw the branch
* \param graphics GDI+
* \param parentAngle the parent's angle
* \param pos the position to draw at
*/
void CBranch::Draw(Gdiplus::Graphics* graphics, double parentAngle, Gdiplus::Point pos)
{
	double useAngle;
	if (sin(GetAngle() + parentAngle) < 0)
	{
		useAngle = GetAngle() + parentAngle + mTree->GetWindSpeed() / 1000;
	}
	else
	{
		useAngle = GetAngle() + parentAngle - mTree->GetWindSpeed() / 1000;
	}
	double dx = cos(useAngle) * mLength;
	double dy = sin(useAngle) * mLength;

	Pen pen(Color(139, 69, 19), (REAL)mWidth);
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)pos.X, (REAL)pos.Y,
		(REAL)(pos.X + dx), (REAL)(pos.Y + dy));

	for (auto child : mTreeParts)
	{
		child->Draw(graphics, useAngle, Point((int)(pos.X + dx), (int)(pos.Y + dy)));
	}
}

/**
* Harvest from the branch
*/
void CBranch::Harvest()
{
	vector<int> deleteFruit;

	int sz = mTreeParts.size();
	for (int i = 0; i < sz; i++)
	{
		CFruitObject* fruit = mTreeParts[i]->PickFruit();
		if (fruit != nullptr)
		{
			deleteFruit.push_back(i);
		}
	}

	sort(deleteFruit.begin(), deleteFruit.end(), greater<int>());

	for (auto i : deleteFruit)
	{
		mTreeParts.erase(mTreeParts.begin() + i);
	}
	
	for (auto branch : mBranches)
	{
		branch->Harvest();
	}
}

/**
* Grow the branch
* \param random the random seed
*/
void CBranch::Grow(CPseudoRandom* random)
{
	double spawnLength = 6.5;
	double growRate = pow((1.0 + GetGrowth()), GetDelta());
	mLength *= growRate;
	mWidth *= growRate;

	if (mLength > spawnLength && !mTreeParts.size())
	{
		if (mDepth > 6 && random->Random(0, 1) < 0.7)
		{
			auto leaf = make_shared<CLeaf>(mTree);
			leaf->SetAngle(random->Random(-0.5, 0.5));
			mTreeParts.push_back(leaf);
		}
		else
		{
			auto limb = make_shared<CBranch>();
			limb->SetAngle(random->Random(-0.5, 0.5));
			limb->SetDepth(mDepth + 1);
			limb->SetTree(mTree);
			mTreeParts.push_back(limb);
			mBranches.push_back(limb);
		}

		if (mDepth > 8 && random->Random(0, 1) < 0.1)
		{
			auto fruit = make_shared<CFruitObject>(mTree);
			fruit->SetAngle(random->Random(-0.2, 0.2)+3.14159);
			mTree->AddFruit(fruit);
			mTreeParts.push_back(fruit);
		}
		else
		{
			auto limb = make_shared<CBranch>();
			limb->SetAngle(random->Random(-0.5, 0.5));
			limb->SetDepth(mDepth + 1);
			limb->SetTree(mTree);
			mTreeParts.push_back(limb);
			mBranches.push_back(limb);
		}
	}

	for (auto child : mTreeParts)
	{
		child->Grow(random);
	}
}

