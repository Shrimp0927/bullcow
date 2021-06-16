// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
    PrintLine(TEXT("Hi! Welcome to the Bull Cows!"));
    PrintLine(FString::Printf(TEXT("Guess the %i letter word"), HiddenWord.Len()));
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (HiddenWord == Input) {
        PrintLine(TEXT("W"));
    } else {
        PrintLine(TEXT("L"));
    }

}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = 3;
}