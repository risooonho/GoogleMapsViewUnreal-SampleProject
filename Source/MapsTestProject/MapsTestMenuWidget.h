// Copyright (c) 2018 Nineva Studios

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interface/GoogleMapsViewInterface.h"
#include "Interface/MarkerInterface.h"
#include "GoogleMapOptions.h"
#include "LatLng.h"
#include "MapsTestMenuWidget.generated.h"

UCLASS()
class MAPSTESTPROJECT_API UMapsTestMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable, Category="GoogleMapsView")
	void HandleCreateMapButtonClick();
	
	UFUNCTION(BlueprintCallable, Category = "GoogleMapsView")
	void HandleShowMapButtonClick();

	UFUNCTION(BlueprintCallable, Category = "GoogleMapsView")
	void HandleHideMapButtonClick();

	UFUNCTION(BlueprintCallable, Category = "GoogleMapsView")
	void HandleDismissMapButtonClick();

	UFUNCTION(BlueprintCallable, Category = "GoogleMapsView")
	void HandleRemoveMarkerButtonClick();

private:

	/**
	* Create dummy map options structure with hardcoded values.
	*/
	FGoogleMapOptions InitMapOptions();

	/**
	* Get bounds of specified widget.
	* @return - pair of vectors with widget bounds (key - widget position in viewport, value - widget size).
	*/
	TPair<FVector2D, FVector2D> GetWidgetBounds(UWidget* widget);

	/** Reference to map view interface. */
	TScriptInterface<IGoogleMapsViewInterface> MapView;

	/** Reference to last added marker interface. */
	TScriptInterface<IMarkerInterface> LastAddedMarker;

	/** 
	* Flag indicating if there is existing map view (used to allow only one map view in demo level).
	* Can be removed to allow creation of multiple map views.
	*/
	bool IsMapViewExist;

	/**
	* Handle OnMapReady callback.
	*/
	UFUNCTION()
	void OnMapViewReady();

	/**
	* Handle OnMapClick callback.
	*/
	UFUNCTION()
	void OnMapViewClick(FLatLng latLng);
};
