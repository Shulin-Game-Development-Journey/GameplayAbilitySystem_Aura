// Shulin's work

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;    //变量AuraContext 类型Input Mapping Context
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;           //变量MoveAction 类型Input Mapping Context
	
	void Move (const struct FInputActionValue& InputActionValue);
	
	void CursorTrace();
	TScriptInterface<IEnemyInterface> LastActor;  //上一帧鼠标指到的敌人
	TScriptInterface<IEnemyInterface> ThisActor;  //当前鼠标指到的敌人
};
