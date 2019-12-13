/**
 * \file TreestuffDlg.cpp
 *
 * \author Becky Henning
 */
// TreestuffDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "TreestuffDlg.h"
#include "afxdialogex.h"


// CTreestuffDlg dialog

IMPLEMENT_DYNAMIC(CTreestuffDlg, CDialog)

CTreestuffDlg::CTreestuffDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, mStartTreeFrame1(mStartTreeFrame1)
	, mStartTreeFrame2(mStartTreeFrame2)
	, mHarvestFrame(mHarvestFrame)
	, mEmptyFrame(mEmptyFrame)
{
}

CTreestuffDlg::~CTreestuffDlg()
{
}

void CTreestuffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_StartFrameTree1, mStartTreeFrame1);
	DDV_MinMaxInt(pDX, mStartTreeFrame1, 0, INT_MAX);
	DDX_Text(pDX, IDC_StartFrameTree2, mStartTreeFrame2);
	DDV_MinMaxInt(pDX, mStartTreeFrame2, 0, INT_MAX);
	DDX_Text(pDX, IDC_HarvestFrame, mHarvestFrame);
	DDV_MinMaxInt(pDX, mHarvestFrame, 0, INT_MAX);
	DDX_Text(pDX, IDC_EmptyBasketFrame, mEmptyFrame);
	DDV_MinMaxInt(pDX, mEmptyFrame, 0, INT_MAX);
}


BEGIN_MESSAGE_MAP(CTreestuffDlg, CDialog)
END_MESSAGE_MAP()


// CTreestuffDlg message handlers

/** Transfer dialog values to the Timeline object
*/
void CTreestuffDlg::Take()
{
	mTree1->SetGrow(mStartTreeFrame1);
	mTree2->SetGrow(mStartTreeFrame2);
	mBasket->SetHarvest(mHarvestFrame);
	mBasket->SetEmpty(mEmptyFrame);
}
