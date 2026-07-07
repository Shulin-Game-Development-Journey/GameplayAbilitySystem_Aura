// Shulin's work

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	
	
	/**Enemy Interface*/
	virtual auto HightlightActor() -> void override;
	virtual void UnHightlightActor() override;
	/**End of enemy interface*/
	
protected:
	virtual void BeginPlay() override;
};
