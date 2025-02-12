#pragma once
//ryanh - PROG72370 - Assignment 1 - Win25

//What is required of each person is:
//		- their unique username
//		- their level(levels can range from 1 – 60)
//		- their faction(red, blue or green).

#define USERNAME_LEN	11	//leaving room for '\0' at the end
#define FACTION_NAME	6

typedef enum faction {RED =1, BLUE =2, GREEN =3} FACTION;

typedef struct user {
	char username[USERNAME_LEN];
	int level;
	FACTION faction;
}USER, *PUSER;

USER generateUser(char* name, int lvl, int faction);

char* generateUsername();
int generateLevel();
int generateFaction();

//utils
void CleanNewLineFromString(char* Name);
