// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CircuitQuestGameGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCircuitQuestGameGameMode() {}

// ********** Begin Cross Module References ********************************************************
CIRCUITQUESTGAME_API UClass* Z_Construct_UClass_ACircuitQuestGameGameMode();
CIRCUITQUESTGAME_API UClass* Z_Construct_UClass_ACircuitQuestGameGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_CircuitQuestGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACircuitQuestGameGameMode ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ACircuitQuestGameGameMode;
UClass* ACircuitQuestGameGameMode::GetPrivateStaticClass()
{
	using TClass = ACircuitQuestGameGameMode;
	if (!Z_Registration_Info_UClass_ACircuitQuestGameGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CircuitQuestGameGameMode"),
			Z_Registration_Info_UClass_ACircuitQuestGameGameMode.InnerSingleton,
			StaticRegisterNativesACircuitQuestGameGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ACircuitQuestGameGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ACircuitQuestGameGameMode_NoRegister()
{
	return ACircuitQuestGameGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACircuitQuestGameGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CircuitQuestGameGameMode.h" },
		{ "ModuleRelativePath", "CircuitQuestGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ACircuitQuestGameGameMode constinit property declarations ****************
// ********** End Class ACircuitQuestGameGameMode constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACircuitQuestGameGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ACircuitQuestGameGameMode_Statics
UObject* (*const Z_Construct_UClass_ACircuitQuestGameGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_CircuitQuestGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACircuitQuestGameGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACircuitQuestGameGameMode_Statics::ClassParams = {
	&ACircuitQuestGameGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACircuitQuestGameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACircuitQuestGameGameMode_Statics::Class_MetaDataParams)
};
void ACircuitQuestGameGameMode::StaticRegisterNativesACircuitQuestGameGameMode()
{
}
UClass* Z_Construct_UClass_ACircuitQuestGameGameMode()
{
	if (!Z_Registration_Info_UClass_ACircuitQuestGameGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACircuitQuestGameGameMode.OuterSingleton, Z_Construct_UClass_ACircuitQuestGameGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACircuitQuestGameGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACircuitQuestGameGameMode);
ACircuitQuestGameGameMode::~ACircuitQuestGameGameMode() {}
// ********** End Class ACircuitQuestGameGameMode **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameGameMode_h__Script_CircuitQuestGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACircuitQuestGameGameMode, ACircuitQuestGameGameMode::StaticClass, TEXT("ACircuitQuestGameGameMode"), &Z_Registration_Info_UClass_ACircuitQuestGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACircuitQuestGameGameMode), 77588526U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameGameMode_h__Script_CircuitQuestGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameGameMode_h__Script_CircuitQuestGame_1343865149{
	TEXT("/Script/CircuitQuestGame"),
	Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameGameMode_h__Script_CircuitQuestGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameGameMode_h__Script_CircuitQuestGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
