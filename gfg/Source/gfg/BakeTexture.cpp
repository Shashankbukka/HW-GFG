// Fill out your copyright notice in the Description page of Project Settings.

#include "BakeTexture.h"

// for DrawMaterialToRenderTarget
#include "Kismet/KismetRenderingLibrary.h"

// only needed for FObjectFinder method
#include "UObject/ConstructorHelpers.h"
#include "Engine/TextureRenderTarget2D.h"


// Sets default values for this component's properties
UBakeTexture::UBakeTexture()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    target = nullptr;
    material = nullptr;
    complete = true;
    
    // alternate approach with hard-coded asset paths
    // remove UPROPERTY from target and material in the .h file and uncomment these lines
    //auto targetObj = ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D>(TEXT("/Game/Assn2/a2-2DCloud-RT.a2-2DCloud-RT"));
    //if (targetObj.Succeeded())
    //    target = targetObj.Object;
    //
    //auto materialObj = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/Assn2/a2-2DCloud-MAT.a2-2DCloud-MAT"));
    //if (materialObj.Succeeded())
    //    material = materialObj.Object;
}


// Called when the game starts
void UBakeTexture::BeginPlay()
{
	Super::BeginPlay();

    // only need to bake if texture and material have been assigned
    if (target && material) {
        UE_LOG(LogTemp, Warning, TEXT("BeginPlay BakeTexture"));
        complete = false;
    }
}


// Called every frame
void UBakeTexture::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!complete) {
        UE_LOG(LogTemp, Warning, TEXT("BakeTexture executing"));
        UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), target, material);
        complete = true;
    }
}

