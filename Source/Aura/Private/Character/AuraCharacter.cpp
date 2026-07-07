// Shulin's work


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

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
