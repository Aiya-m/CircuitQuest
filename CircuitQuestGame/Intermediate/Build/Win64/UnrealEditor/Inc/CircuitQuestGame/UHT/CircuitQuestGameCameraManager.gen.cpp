// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CircuitQuestGameCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCircuitQuestGameCameraManager() {}

// ********** Begin Cross Module References ********************************************************
CIRCUITQUESTGAME_API UClass* Z_Construct_UClass_ACircuitQuestGameCameraManager();
CIRCUITQUESTGAME_API UClass* Z_Construct_UClass_ACircuitQuestGameCameraManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
UPackage* Z_Construct_UPackage__Script_CircuitQuestGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACircuitQuestGameCameraManager *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ACircuitQuestGameCameraManager;
UClass* ACircuitQuestGameCameraManager::GetPrivateStaticClass()
{
	using TClass = ACircuitQuestGameCameraManager;
	if (!Z_Registration_Info_UClass_ACircuitQuestGameCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CircuitQuestGameCameraManager"),
			Z_Registration_Info_UClass_ACircuitQuestGameCameraManager.InnerSingleton,
			StaticRegisterNativesACircuitQuestGameCameraManager,
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
	return Z_Registration_Info_UClass_ACircuitQuestGameCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_ACircuitQuestGameCameraManager_NoRegister()
{
	return ACircuitQuestGameCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "CircuitQuestGameCameraManager.h" },
		{ "ModuleRelativePath", "CircuitQuestGameCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ACircuitQuestGameCameraManager constinit property declarations ***********
// ********** End Class ACircuitQuestGameCameraManager constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACircuitQuestGameCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics
UObject* (*const Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_CircuitQuestGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics::ClassParams = {
	&ACircuitQuestGameCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics::Class_MetaDataParams)
};
void ACircuitQuestGameCameraManager::StaticRegisterNativesACircuitQuestGameCameraManager()
{
}
UClass* Z_Construct_UClass_ACircuitQuestGameCameraManager()
{
	if (!Z_Registration_Info_UClass_ACircuitQuestGameCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACircuitQuestGameCameraManager.OuterSingleton, Z_Construct_UClass_ACircuitQuestGameCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACircuitQuestGameCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACircuitQuestGameCameraManager);
ACircuitQuestGameCameraManager::~ACircuitQuestGameCameraManager() {}
// ********** End Class ACircuitQuestGameCameraManager *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameCameraManager_h__Script_CircuitQuestGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACircuitQuestGameCameraManager, ACircuitQuestGameCameraManager::StaticClass, TEXT("ACircuitQuestGameCameraManager"), &Z_Registration_Info_UClass_ACircuitQuestGameCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACircuitQuestGameCameraManager), 575629312U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameCameraManager_h__Script_CircuitQuestGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameCameraManager_h__Script_CircuitQuestGame_4294082167{
	TEXT("/Script/CircuitQuestGame"),
	Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameCameraManager_h__Script_CircuitQuestGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_iyara_OneDrive_Desktop_SeniorProject_CircuitQuest_CircuitQuestGame_Source_CircuitQuestGame_CircuitQuestGameCameraManager_h__Script_CircuitQuestGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
