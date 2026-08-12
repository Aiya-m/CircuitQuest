// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCircuitQuestGame_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	CIRCUITQUESTGAME_API UFunction* Z_Construct_UDelegateFunction_CircuitQuestGame_BulletCountUpdatedDelegate__DelegateSignature();
	CIRCUITQUESTGAME_API UFunction* Z_Construct_UDelegateFunction_CircuitQuestGame_DamagedDelegate__DelegateSignature();
	CIRCUITQUESTGAME_API UFunction* Z_Construct_UDelegateFunction_CircuitQuestGame_PawnDeathDelegate__DelegateSignature();
	CIRCUITQUESTGAME_API UFunction* Z_Construct_UDelegateFunction_CircuitQuestGame_SprintStateChangedDelegate__DelegateSignature();
	CIRCUITQUESTGAME_API UFunction* Z_Construct_UDelegateFunction_CircuitQuestGame_UpdateSprintMeterDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_CircuitQuestGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_CircuitQuestGame()
	{
		if (!Z_Registration_Info_UPackage__Script_CircuitQuestGame.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_CircuitQuestGame_BulletCountUpdatedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_CircuitQuestGame_DamagedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_CircuitQuestGame_PawnDeathDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_CircuitQuestGame_SprintStateChangedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_CircuitQuestGame_UpdateSprintMeterDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/CircuitQuestGame",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x56B5D2CC,
			0x964D862D,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_CircuitQuestGame.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_CircuitQuestGame.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_CircuitQuestGame(Z_Construct_UPackage__Script_CircuitQuestGame, TEXT("/Script/CircuitQuestGame"), Z_Registration_Info_UPackage__Script_CircuitQuestGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x56B5D2CC, 0x964D862D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
