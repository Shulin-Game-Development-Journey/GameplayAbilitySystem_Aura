// Shulin's work


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;    //多人同步游戏
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
	CursorTrace();
	
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if (!CursorHit.bBlockingHit) return;
	
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
	
	/**
 * 鼠标射线检测（Cursor Trace），共有以下几种情况：
 *
 * A. LastActor 和 ThisActor 都为空（nullptr）
 *    - 什么都不做
 *
 * B. LastActor 为空，ThisActor 有效
 *    - 高亮 ThisActor
 *
 * C. LastActor 有效，ThisActor 为空
 *    - 取消高亮 LastActor
 *
 * D. LastActor 和 ThisActor 都有效，但不是同一个 Actor
 *    - 取消高亮 LastActor
 *    - 高亮 ThisActor
 *
 * E. LastActor 和 ThisActor 都有效，并且是同一个 Actor
 *    - 什么都不做
 */
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//case B
			ThisActor->HightlightActor();
		}
		else
		{
				//case A -Both are null, do nothing
		}
	}
	else //LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			//case C
			LastActor->UnHightlightActor();
		}
		else //Both actor are valid
		{
			if (LastActor != ThisActor)
			{
				//Case D Last actor is unhightligh actor 
				LastActor->UnHightlightActor();
				ThisActor->HightlightActor();
			}
			else
			{
				//CASE E_do nothing
			}
		}
	}
	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check (AuraContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer :: GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;       //使用默认鼠标样式。Default 就是默认鼠标样子
	
	FInputModeGameAndUI InputModeData;             //Make InputMode Game and UI还没应用先做出来
	InputModeData. SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);  //鼠标不要锁在游戏窗口。
	InputModeData. SetHideCursorDuringCapture(false); //鼠标点击的时候,不要隐藏鼠标。
	SetInputMode(InputModeData);                 //把刚才配置好的真正应用到 PlayerController。
	
}

void AAuraPlayerController::SetupInputComponent()    //开始绑定输入事件
{
	Super::SetupInputComponent();     //先执行父类 PlayerController 的 SetupInputComponent。
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent> (InputComponent);
	//绑定输入, Input Action (IA_Move),一直按住一直调用,当前 PlayerController执行，按键触发以后调用Move函数，也就是把 IA_Move 绑定到 Move()。
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent :: Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const struct FInputActionValue& InputActionValue)    //写Move() 函数，Input Action 传进来的值
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();  //取得XY ‘Break Vector2Dfrom传进来的值’
	const FRotator Rotation = GetControlRotation();                       //Get Control Rotation
	const FRotator YawRotation (0.f, Rotation.Yaw, 0.f);                //只保留左右方向
	//根据摄像机方向算出前方方向，前方方向和摄像机朝向一致，
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//和上句一样， 获得右边方向
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())                  //Get Controlled Pawn
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector. Y);   //朝前移动
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector. X);     //左右移动
	}
}

