//ryanh - PROG72370 - Assignment 1 - Win25
#define _CRT_SECURE_NO_WARNINGS

#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//Generates and returns entire user
USER generateUser(char* name, int lvl, int faction) {
	USER temp = { 0 };

	strncpy(temp.username, name, USERNAME_LEN);	//assign username to a user
	CleanNewLineFromString(temp.username);		
	temp.level = lvl;		//assign a level to a user
	temp.faction = faction;	//assign a faction ENUM to a user

	return temp;
}

// Generates a random 10 character long username
char* generateUsername() {
	char name[USERNAME_LEN] = { '\0' };
	char possibleChars[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };	//usable characters for username
	for (int i = 0; i < USERNAME_LEN; i++) {
		int randIndex = rand() % (sizeof(possibleChars) - 1);	//indexes a number within certain range
		name[i] = possibleChars[randIndex];	//uses the indexed number to assign a letter from usable username characters to a username
	}
	name[USERNAME_LEN-1] = '\0';		//null terminate string
	
	//printf("%s", test);	//testing purposes
	return name;
}

// Generates a random level between 1 and 60
int generateLevel() {
	int level = rand() % 60 + 1;	
	//printf("%d\n", level);	//testing purposes
	return level;
}

// Generates a random number between 1-3 (RED =1, BLUE =2, GREEN =3)
int generateFaction() {
	int type = rand() % 3 + 1;	// random number generator between 1 and 3
	return type;
}


//utils
void CleanNewLineFromString(char* Name) {	//pulled from previous classes, cleans up string to prevent errors
	for (int i = 0; i < strlen(Name); i++)
		if (Name[i] == '\n')
			Name[i] = '\0';
}