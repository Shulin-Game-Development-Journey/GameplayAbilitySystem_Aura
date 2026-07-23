// Shulin's work


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;


void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	// Primary Attributes
	
	GameplayTags. Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"), 
		FString ("Increase Physical Damage"));
	
	GameplayTags. Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"), 
		FString ("Increase Magical Damage"));
	
	GameplayTags. Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"), 
		FString ("Increase Armor and Armor Penetration"));
	
	GameplayTags. Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"), 
		FString ("Increase Health"));
	
	// Secondary Attributes 
	
	GameplayTags. Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"), 
		FString ("Reduce damage taken, improve Block Chance"));
	
	GameplayTags. Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorPenetration"), 
		FString ("Ignore Percentage of Enemy Armor, increase Critical Hit Chance"));
	
	GameplayTags. Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"), 
		FString ("Chance to cut incoming damage in half"));
	
	GameplayTags. Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CriticalHitChance"), 
	FString ("Chance to double damage plus critical hit bonus"));
	
	GameplayTags. Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CriticalHitDamage"), 
	FString ("Bonus Damage added when a critical hit is scored"));
		
	GameplayTags. Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CriticalHitResistance"), 
	FString ("Reduce Critical Hit Chance of attacking enemies"));	
	
	GameplayTags. Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.HealthRegeneration"), 
	FString ("Amount of Health Regenerated every 1 second"));
	
	GameplayTags. Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.ManaRegeneration"), 
	FString ("Amount of Mana Regenerated every 1 second"));
	
	GameplayTags. Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.MaxHealth"), 
	FString ("Maximum Amount of Health Obtainable"));
	
	GameplayTags. Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.MaxMana"), 
	FString ("Maximum Amount of Mana Obtainable"));
		
		
}


