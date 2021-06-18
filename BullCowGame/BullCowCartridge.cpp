// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver) {
        ClearScreen();
        InitGame();
    } else {
        ClearScreen();
        if (HiddenWord == Input) {
            PrintLine(TEXT("W"));
            GameOver();
        } else {
            Lives--;
            if (Lives > 0) {
                PrintLine(TEXT("try again \n%i lives remaining"), Lives);
            } else {
                PrintLine(TEXT("L"));
                GameOver();
            }
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
    bGameOver = 1;
    PrintLine(TEXT("Enter to play again..."));
}