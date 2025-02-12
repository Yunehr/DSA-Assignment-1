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
	char username[USERNAME_LEN];	// randomly generated: 10 characters long
	int level;						// between 1-60: randomly generated
	FACTION faction;				// randomly generated ENUM
}USER, *PUSER;

//Generates and returns entire user
USER generateUser(char* name, int lvl, int faction);	

char* generateUsername();	// Generates a random 10 character long username
int generateLevel();		// Generates a random level between 1 and 60
int generateFaction();		// Generates a random number between 1-3 (RED =1, BLUE =2, GREEN =3)

//utils
void CleanNewLineFromString(char* Name);
