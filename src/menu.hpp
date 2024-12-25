#pragma once

#include <iostream>

void clearScreen();
void displayMainMenu();
void displayPage(const char* username, const char* password, bool isLogin, bool showPassword);
void handleInput(bool isLogin);
void signup(string username, string password);
void handleMainMenuChoice();