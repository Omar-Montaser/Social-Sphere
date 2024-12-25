#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H
#include "User.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"

void loginScreen(Graph& network);
void viewFriends(User& currentUser, Graph& network);
void addFriend(User& currentUser, Graph& network);
void viewFriendRecommendations(User& currentUser, Graph& network);
PriorityQueue recommendFriends(User currentUser,Graph& network);
void displayRecommendations(PriorityQueue& pq);
void viewSocialSphere(Graph& network);
void displayMenu(User& currentUser,Graph& network);

#endif // USERDASHBOARD_H