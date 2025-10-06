// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/UIS_ActivatableScreen.h"
#include "Input/CommonUIActionRouterBase.h"
#include "HUD/UIS_HUD.h"
#include "UI/UIS_GameLayout.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(UIS_ActivatableScreen)

UUIS_ActivatableScreen::UUIS_ActivatableScreen()
{
	// Ensure that all activatable screens can handle generic "back" actions by default 
	bIsBackHandler = true;
}

void UUIS_ActivatableScreen::RefreshUIInputConfig()
{
	if (UCommonUIActionRouterBase* ActionRouter = UCommonUIActionRouterBase::Get(*this))
	{
		ActionRouter->RefreshUIInputConfig();
	}
}

bool UUIS_ActivatableScreen::NativeOnHandleBackAction()
{
	// Invoke our back event 
	OnGenericBackTriggered(); 

	return true; 
}

void UUIS_ActivatableScreen::CloseScreen()
{
	// Find the HUD from the owning player controller and remove this widget from its layer
	if (const TObjectPtr<APlayerController> PlayerController = GetOwningPlayer())
	{
		if (const TObjectPtr<AUIS_HUD> HUD = PlayerController->GetHUD<AUIS_HUD>())
		{
			if (const TObjectPtr<UUIS_GameLayout> Root = HUD->GetRootLayoutWidget())
			{
				Root->FindAndRemoveWidgetFromLayer(this); 
			}
		}
	}
}