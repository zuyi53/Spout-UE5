// Fill out your copyright notice in the Description page of Project Settings.


#include "SpoutSendCommandlet.h"

USpoutSendCommandlet::USpoutSendCommandlet()
{

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> Object0;
		FConstructorStatics()
			:Object0(TEXT("TextureRenderTarget2D'/SpoutPlugin/Textures/RT_RenderTarget2D.RT_RenderTarget2D'"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	//  Ù–‘≥ı ºªØ
	textureRenderTarget2D = ConstructorStatics.Object0.Object;
	
}

int32 USpoutSendCommandlet::Main(const FString& Params)
{
	UE_LOG(LogTemp, Log, TEXT("Initial Spout "));

	TArray<FString> DefaultGameMode = { 
		TEXT("[/Script/EngineSettings.GameMapsSettings]"), 
		TEXT("GlobalDefaultGameMode=/SpoutPlugin/GameMode/GM_baiman.GM_baiman_C") 
	};

	IFileManager& FileManager = IFileManager::Get();

	TArray<FString> DefaultEngineINI;
	FString PathToFile;

	PathToFile = FPaths::ProjectConfigDir()+ TEXT("DefaultEngine.ini");

	UE_LOG(LogTemp, Warning, TEXT("ini path %s"), *PathToFile);
	FFileHelper::LoadFileToStringArray(DefaultEngineINI, *PathToFile);

	DefaultEngineINI.Append(DefaultGameMode);

	if (FFileHelper::SaveStringArrayToFile(DefaultEngineINI, *PathToFile, FFileHelper::EEncodingOptions::AutoDetect, &FileManager, 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Default Game ini override successful "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Default Game ini override Fault "));
	}


	return int32();
}
