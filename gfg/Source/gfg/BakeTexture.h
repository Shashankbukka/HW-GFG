// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BakeTexture.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GFG_API UBakeTexture : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBakeTexture();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    // Render target to bake material into
    UPROPERTY(EditAnywhere)
    UTextureRenderTarget2D *target;
    
    // Material to bake into render target
    UPROPERTY(EditAnywhere)
    UMaterialInterface *material;
    
private:
    // initialize just once on first tick
    bool complete;};
