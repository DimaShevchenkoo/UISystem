// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "GameFramework/HUD.h"
#include "UIS_HUD.generated.h"

class UUIS_GameLayout;
class UCommonActivatableWidget;

UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameLayer)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(ModalLayer)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(MenuLayer)
UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameMenuLayer)

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitialWidgetPushedToStackDelegate);

UCLASS(Abstract, Blueprintable)
class UISYSTEM_API AUIS_HUD : public AHUD
{
	GENERATED_BODY()

public: 
	// Called when play begins for this actor 
	virtual void BeginPlay() override; 

	// Getter for the root layout widget 
	TObjectPtr<UUIS_GameLayout> GetRootLayoutWidget() { return RootLayoutWidget; }

protected:
	UPROPERTY(BlueprintAssignable)
	FOnInitialWidgetPushedToStackDelegate OnInitialWidgetPushedToStack;
	
	// Layout class to use to setup the UI layout
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI")
	TObjectPtr<UUIS_GameLayout> RootLayoutWidget;

	// HUD widget class to create during startup
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI")
	TSoftClassPtr<UCommonActivatableWidget> DefaultWidgetClass;

	// The UI layer to create the HUD in
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (Categories = "UI.Layer"))
	FGameplayTag DefaultLayerName;

	// The instanced default widget 
	TObjectPtr<UCommonActivatableWidget> DefaultWidget;
};
