
#include "SItemChest.h"
#include <Components/StaticMeshComponent.h>

ASItemChest::ASItemChest()
{
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	BaseMesh->SetupAttachment(RootComponent);
	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);



}

void ASItemChest::Interact_Implementation(APawn* InstigatorPawm)
{
	LidMesh->SetRelativeRotation(FRotator(110.0f, 0.0f, 0.0f));
}

void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

