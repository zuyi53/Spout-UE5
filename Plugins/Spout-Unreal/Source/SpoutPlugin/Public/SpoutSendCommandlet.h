// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpoutBPFunctionLibrary.h"
#include "Commandlets/Commandlet.h"
#include "SpoutSendCommandlet.generated.h"

/**
 * 
 */
UCLASS()
class SPOUTPLUGIN_API USpoutSendCommandlet : public UCommandlet
{
	GENERATED_BODY()
public:
	USpoutSendCommandlet();

	virtual int32 Main(const FString& Params);

	FString project_name;

	FName spoutName;

	ESpoutSendTextureFrom sendTextureFrom;

	float targetGamma = 1.0;

	UTextureRenderTarget2D* textureRenderTarget2D;
};
