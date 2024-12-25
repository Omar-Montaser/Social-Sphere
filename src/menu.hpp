#pragma once

#include <iostream>
#include "Graph.hpp"
void clearScreen();
void displayMainMenu(Graph& network);
void displayPage(bool isLogin, Graph& network);
void signup(string username, string password,Graph& network);
void handleMainMenuChoice(Graph& network);