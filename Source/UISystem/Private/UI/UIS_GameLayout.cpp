// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/UIS_GameLayout.h"

void UUIS_GameLayout::RegisterLayer(const FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* LayerWidget)
{
	if (!IsDesignTime())
	{
		Layers.Add(LayerTag, LayerWidget);
	}
}

TObjectPtr<UCommonActivatableWidgetContainerBase> UUIS_GameLayout::GetLayerWidget(const FGameplayTag LayerName) const
{
	return Layers.FindRef(LayerName);
}

void UUIS_GameLayout::FindAndRemoveWidgetFromLayer(UCommonActivatableWidget* ActivatableWidget)
{
	for (const auto& LayerPair : Layers)
	{
		if (!LayerPair.Value->GetWidgetList().Contains(ActivatableWidget))
		{
			continue;
		}

		LayerPair.Value->RemoveWidget(*ActivatableWidget);
		break;
	}
}