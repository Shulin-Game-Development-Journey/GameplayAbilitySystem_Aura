// Shulin's work


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "UI/HUB/AuraHUD.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;                  //角色朝移动方向转
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);  //转动速度，每秒最多旋转400度，越小人物越笨重
	GetCharacterMovement()->bConstrainToPlane = true;              //限制在移动平面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;            //人物出生离地高点也会贴到平面
	//Controller 不控制角色旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
}

void AAuraCharacter::PossessedBy(AController* NewController)  //服务器上，当 Controller 控制这个角色以后，初始化 GAS。
{
	Super::PossessedBy(NewController);
	
	//Init ability actor info for the server
	InitAbilityActorInfo();
	
}

void AAuraCharacter::OnRep_PlayerState()      //客户端收到 PlayerState 同步以后，初始化 GAS。
{
	Super::OnRep_PlayerState();
	
	//Init ability actor info for the client
	InitAbilityActorInfo();
}

int32 AAuraCharacter::GetPlayerLevel()
{
	const AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState); 
	return AuraPlayerState->GetPlayerLevel();
}

void AAuraCharacter::InitAbilityActorInfo()    //写函数InitAbilityActorInfo
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();  //1.创建变量AuraPlayerState
	//2.变量类型：AAuraPlayerState Object Reference 
	//从当前 Character 身上拿 PlayerState
	check(AuraPlayerState);                        //检查有没有拿到
	//把 AbilitySystemComponent（ASC）拿出来，然后调用它的 InitAbilityActorInfo()，告诉 ASC 它属于谁、控制谁。
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet(); //请仔细理解attribute和ABS在体系的不同赋值程序
	
	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD-> InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	 InitializeDefaultAttributes();
} 
