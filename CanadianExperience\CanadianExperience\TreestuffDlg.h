/**
 * \file TreestuffDlg.h
 *
 * \author Becky Henning
 *
 * The dialog box for harvesting/growing
 */

#pragma once

#include "TreeAdapter.h"
#include "BasketAdapter.h"

#include <memory>

// CTreestuffDlg dialog

/**
 * Dialog box for harvesting and growing with basket and tree adapters
 */
class CTreestuffDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreestuffDlg)

public:
	/// Constructor
	/// \param pParent is null
	CTreestuffDlg(CWnd* pParent = nullptr);
	virtual ~CTreestuffDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

	/// Set the member variables
	/// \param tree1 tree 1
	/// \param tree2 tree 2
	/// \param basket the basket
	void SetVariables(std::shared_ptr<CTreeAdapter> tree1, std::shared_ptr<CTreeAdapter> tree2, std::shared_ptr<CBasketAdapter> basket)
	{
		mTree1 = tree1, mTree2 = tree2, mBasket = basket, 
		mStartTreeFrame1 = mTree1->GetGrow(), mStartTreeFrame2 = mTree2->GetGrow(), 
		mHarvestFrame = mBasket->GetHarvest(), mEmptyFrame = mBasket->GetEmpty(); 
	}

	/// Update the values on changes
	void Take();

protected:
	/// DDX/DDV support
	/// \param pDX the parent data exchange
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
private:
	/// tree1 grow
	int mStartTreeFrame1;

	/// tree2 grow
	int mStartTreeFrame2;

	/// basket harvest frame
	int mHarvestFrame;

	/// basket empty frame
	int mEmptyFrame;

	/// tree 1
	std::shared_ptr<CTreeAdapter> mTree1 = nullptr;

	/// tree 2
	std::shared_ptr<CTreeAdapter> mTree2 = nullptr;

	/// tree 3
	std::shared_ptr<CBasketAdapter> mBasket = nullptr;
};
