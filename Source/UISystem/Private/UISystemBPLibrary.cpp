// Copyright Epic Games, Inc. All Rights Reserved.

#include "UISystemBPLibrary.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/NavigationConfig.h"
#include "HUD/UIS_HUD.h"
#include "UI/UIS_GameLayout.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(UISystemBPLibrary)

DEFINE_LOG_CATEGORY(LogUserInterfaceBlueprintLibrary);

UCommonActivatableWidget* UUISystemBPLibrary::PushContentToLayerForPlayer(const APlayerController* Player, FGameplayTag LayerName, TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	if (!Player || WidgetClass == nullptr)
	{
		UE_LOG(LogUserInterfaceBlueprintLibrary, Error, TEXT("UUserInterfaceBlueprintLibrary::PushContentToLayerForPlayer, invalid player parameter or widget class returning nullptr."));
		return nullptr;
	}

	// Get the player's HUD and attempt to create and return the widget
	if (TObjectPtr<AUIS_HUD> HUD = Player->GetHUD<AUIS_HUD>())
	{
		if (TObjectPtr<UUIS_GameLayout> RootLayout = HUD->GetRootLayoutWidget())
		{
			TObjectPtr<UCommonActivatableWidget> NewWidget = RootLayout->PushWidgetToLayerStack(LayerName, WidgetClass);
			return NewWidget;
		}
	}

	return nullptr;
}

void UUISystemBPLibrary::SetNavigationEnabled(bool bIsNavEnabled)
{
	FSlateApplication::Get().GetNavigationConfig()->bTabNavigation = bIsNavEnabled;
	FSlateApplication::Get().GetNavigationConfig()->bKeyNavigation = bIsNavEnabled;
	FSlateApplication::Get().GetNavigationConfig()->bAnalogNavigation = bIsNavEnabled;
}

FString UUISystemBPLibrary::GetProjectVersion()
{
	FString AppVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		AppVersion,
		GGameIni
	);

	return AppVersion; 
}
