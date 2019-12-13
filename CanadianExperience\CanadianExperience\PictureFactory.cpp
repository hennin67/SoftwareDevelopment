/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "BasketAdapter.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);

	// Create and add tree 1
	auto treeActor1 = make_shared<CActor>(L"tree actor 1");
	treeActor1->SetPosition(Point(600, 300));

	auto treeAdapter1 = make_shared<CTreeAdapter>(L"tree1");
	treeActor1->AddDrawable(treeAdapter1);
	treeActor1->SetRoot(treeAdapter1);
	picture->AddActor(treeActor1);
	picture->AddTree1(treeAdapter1);

	// Create and add tree 2
	auto treeActor2 = make_shared<CActor>(L"tree actor 2");
	treeActor2->SetPosition(Point(800, 450));

	auto treeAdapter2 = make_shared<CTreeAdapter>(L"tree2");
	treeActor2->AddDrawable(treeAdapter2);
	treeActor2->SetRoot(treeAdapter2);
	picture->AddActor(treeActor2);
	picture->AddTree2(treeAdapter2);

	// Create and add basket
	auto basketActor = make_shared<CActor>(L"basket actor");
	basketActor->SetPosition(Point(550, 380));

	auto basketAdapter = make_shared<CBasketAdapter>(L"basket");
	basketActor->AddDrawable(basketAdapter);
	basketActor->SetRoot(basketAdapter);
	picture->AddActor(basketActor);
	picture->AddBasket(basketAdapter);

	basketAdapter->AddTree(treeAdapter1);
	basketAdapter->AddTree(treeAdapter2);

    return picture;
}
