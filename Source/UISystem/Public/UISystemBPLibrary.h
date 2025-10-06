// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UISystemBPLibrary.generated.h"

class UCommonActivatableWidget;
struct FGameplayTag;

DECLARE_LOG_CATEGORY_EXTERN(LogUserInterfaceBlueprintLibrary, Log, All);

UCLASS()
class UISYSTEM_API UUISystemBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Create a new widget and add to target layer. 
	// This new widget is activated and displayed on player's viewport
	UFUNCTION(BlueprintCallable, Category = "UI")
	static UCommonActivatableWidget* PushContentToLayerForPlayer(const APlayerController* PlayerController, UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerName, UPARAM(meta = (AllowAbstract = false)) TSubclassOf<UCommonActivatableWidget> WidgetClass);

	// Toggles the player's ability to use gamepad navigation in UMG 
	UFUNCTION(BlueprintCallable, Category = "UI")
	static void SetNavigationEnabled(bool bIsNavEnabled); 

	// Pulls the project version as an FString from the Project Settings 
	UFUNCTION(BlueprintCallable, Category = "UI")
	static FString GetProjectVersion(); 
};
