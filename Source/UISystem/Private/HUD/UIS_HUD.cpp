// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/UIS_HUD.h"
#include "UI/UIS_GameLayout.h"
#include "CommonActivatableWidget.h"

UE_DEFINE_GAMEPLAY_TAG(GameLayer, "UI.Layer.Game")
UE_DEFINE_GAMEPLAY_TAG(ModalLayer, "UI.Layer.Modal")
UE_DEFINE_GAMEPLAY_TAG(MenuLayer, "UI.Layer.Menu")
UE_DEFINE_GAMEPLAY_TAG(GameMenuLayer, "UI.Layer.GameMenu")

void AUIS_HUD::BeginPlay()
{
	Super::BeginPlay();
	
	ensureMsgf(IsValid(RootLayoutWidget), TEXT("Invalid root widget in AUIS_HUD::BeginPlay - check your class setup in editor"));

	// Assign the widget's owner to the owner of the HUD
	RootLayoutWidget->SetOwningPlayer(GetOwningPlayerController()); 

	// Add the widget to the player's screen as the root widget 
	RootLayoutWidget->AddToPlayerScreen(); 

	// Load and add the first widget on the specified layer
	// Subsequent screens can just be stacked upon the root per layer using PushWidgetToLayerStack
	TSubclassOf<UCommonActivatableWidget> HUDWidgetClass = DefaultWidgetClass.LoadSynchronous();
	DefaultWidget = RootLayoutWidget->PushWidgetToLayerStack(DefaultLayerName, HUDWidgetClass);

	OnInitialWidgetPushedToStack.Broadcast();
}
