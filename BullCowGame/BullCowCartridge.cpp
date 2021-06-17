// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (bGameOver == 1) {
        GameOver();
    }
    if (HiddenWord == Input) {
        PrintLine(TEXT("W"));
        bGameOver = 1;
    } else {
        Lives--;
        if (Lives > 0) {
            PrintLine(TEXT("guess again"));
        } else {
            PrintLine(TEXT("L"));
            ClearScreen();
            PrintLine(TEXT("Press enter to continue"));
            bGameOver = 1;
        }
    }
}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = 3;
    bGameOver = 0;
    PrintLine(TEXT("Hi! Welcome to the Bull Cows!"));
    PrintLine(FString::Printf(TEXT("Guess the %i letter word"), HiddenWord.Len()));
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::GameOver() {
    ClearScreen();
    InitGame();
}