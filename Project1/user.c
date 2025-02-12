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

	strncpy(temp.username, name, USERNAME_LEN);
	CleanNewLineFromString(temp.username);
	temp.level = lvl;
	temp.faction = faction;

	return temp;
}

// Generates a random 10 character long username
char* generateUsername() {
	char test[USERNAME_LEN] = { '\0' };
	char possibleChars[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };
	for (int i = 0; i < USERNAME_LEN; i++) {
		int randIndex = rand() % (sizeof(possibleChars) - 1);	//make sure rand() is seeded properly in before use
		test[i] = possibleChars[randIndex];
	}
	test[USERNAME_LEN-1] = '\0';		//null terminate string
	
	//printf("%s", test);	//testing purposes
	return test;
}

// Generates a random level between 1 and 60
int generateLevel() {
	int level = rand() % 60 + 1;	
	//printf("%d\n", level);	//testing purposes
	return level;
}

// Generates a random faction (Red, Blue, or Green)
int generateFaction() {
	int type = rand() % 3 + 1;	// random number generator between 1 and 3
	return type;
}


//utils
void CleanNewLineFromString(char* Name) {
	for (int i = 0; i < strlen(Name); i++)
		if (Name[i] == '\n')
			Name[i] = '\0';
}