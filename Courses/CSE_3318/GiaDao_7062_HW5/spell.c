#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "spell.h"

/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MAX_LEN:
Student answer:  Theta( (MAX_LEN)^2 * D * T )


Worst case to do an unsuccessful binary search in a dictionary with D words, when 
all dictionary words and the searched word have length MAX_LEN 
Student answer:  Theta( log(D) )
*/


/* You can write helper functions here */


/*
Parameters:
first_string - pointer to the first string (displayed vertical in the table)
second_string - pointer to the second string (displayed horizontal in the table)
print_table - If 1, the table with the calculations for the edit distance will be printed.
              If 0 (or any value other than 1)it will not print the table
(See sample run)
Return:  the value of the edit distance (e.g. 3)
*/

void PrintArray(int hori, int vert, int a[vert][hori], char* vertical, char* horizontal)
{
	int t, p;
	printf("%3c|", ' ');
	for(t = 0; t < hori; t++)
	{
		printf("%3c|", horizontal[t]);
	}
	printf("\n");
	for(t = 0; t < hori + 1; t++)
	{
		printf("----");
	}
	printf("\n");
	
	for(t = 0; t < vert; t++)
	{
		printf("%3c|", vertical[t]);
		for(p = 0; p < hori; p++)
		{
			printf("%3d|", a[t][p]);
		}
		printf("\n");
		
		for(p = 0; p < hori + 1; p++)
		{
			printf("----");
		}
		printf("\n");
	}
	printf("\n");

	//free(horizontal);
	//free(vertical);
}


int find_min(int above, int left, int diagonal)
{
	if(above <= left && above <= diagonal)
	{
		return above;
	}

	if(left <= above && left <= diagonal)
	{
		return left;
	}

	if(diagonal <= above && diagonal <= left)
	{
		return diagonal;
	}
}


int edit_distance(char * first_string, char * second_string, int print_table){

	char* empty = " ";
	
	char* vertical = (char*) malloc(1 + strlen(first_string) + strlen(empty));	

	vertical = strcpy(vertical, empty);
	vertical = strcat(vertical, first_string);
	
	char* horizontal = (char*) malloc(1 + strlen(second_string) + strlen(empty));
	
	horizontal = strcpy(horizontal, empty);
	horizontal = strcat(horizontal, second_string);


	int len_ver = strlen(vertical);
	int len_hor = strlen(horizontal);
	
	
	int dist[len_ver][len_hor];
	
	dist[0][0] = 0;
	
	int h;
	for(h = 1; h < len_hor; h++)
	{
		dist[0][h] = dist[0][h - 1] + 1;
	}

	int v;
	for(v = 1; v < len_ver; v++)
	{
		dist[v][0] = dist[v - 1][0] + 1;
	}

	int i, j;
	for (i = 1; i < len_ver; i++)
	{
		for(j = 1; j < len_hor; j++)
		{
			if(horizontal[j] == vertical[i])
			{
				dist[i][j] = find_min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1]);
			}

			if(horizontal[j] != vertical[i])
			{
				dist[i][j] = find_min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1] + 1);
			}
		}
	}
	
	
	if(print_table == 1)
	{
		PrintArray(len_hor, len_ver, dist, vertical, horizontal);
	}

	free(horizontal);
	free(vertical);

	int final = dist[len_ver - 1][len_hor - 1];
	return final;
}
	  

/*
Parameters:
testname - string containing the name of the file with the paragraph to spell check, includes .txt e.g. "text1.txt" 
dictname - name of file with dictionary words. Includes .txt, e.g. "dsmall.txt"
printOn - If 1 it will print EXTRA debugging/tracing information (in addition to what it prints when 0):
			 dictionary as read from the file	
			 dictionary AFTER sorting in lexicographical order
			 for every word searched in the dictionary using BINARY SEARCH shows all the "probe" words and their indices indices
			 See sample run.
	      If 0 (or anything other than 1) does not print the above information, but still prints the number of probes.
		     See sample run.
*/
int minimum_distance(int dict_size, int min_dist[dict_size])
{
	int i, min = INT_MAX;
	for(i = 0; i < dict_size; i++)
	{
		if(min_dist[i] < min)
		{
			min = min_dist[i];
		}
	}
	return min;
}

void PrintWordMin(int count, char* printword[count])
{
	int i;
	for(i = 0; i < count; i++)
	{
		printf(" %d - %s\n", i + 1, printword[i]);
	}
}

void User_Choice(char* old_version, int count, char* save_min_words[count], FILE* fo)
{
	int num_choice, i;
	char correct_word[20];
	printf("\nEnter your choice (from the above options): ");
	scanf("%d", &num_choice);
	if(num_choice == -1)
	{
		printf("\nEnter correct word: ");
		scanf("%s", correct_word);
		fprintf(fo, "%s ", correct_word);
		return;
	}
	else if(num_choice == 0)
	{
		fprintf(fo, "%s ", old_version);
		return;
	}
	else
	{
		for(i = 0; i < count; i++)
		{
			if(num_choice == (i + 1))
			{
				fprintf(fo, "%s ", save_min_words[i]);
			}
		}
		return;
	}
}

void SearchWord(char* word, int dict_size, char* dict[dict_size], int printOn, char* old_version, FILE* fo)
{
	
	if(fo == NULL)
	{
		return;
	}

	int left = 0, right = dict_size - 1, mid;
	int total = 0;
	bool check = false;
	if(printOn == 1) printf("\nBinary search for: %s\n", word);
	while(left <= right)
	{
		mid = (left + right) / 2;
		
		if(printOn == 1)
		{
			printf("dict[%d] = %s\n", mid, dict[mid]);
		}	
		
		total = total + 1;
		if(strcmp(word, dict[mid]) == 0)
		{
			check = true;
			break;
		}
		else if(strcmp(word, dict[mid]) > 0)
		{
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}

	int min_distance[dict_size];
	int k = 0, track = 0, count;
	int compare;
	int result_min_distance;
	char* save_min_words[dict_size];
	
	if(check == false) 
	{
		if(printOn == 1) printf("\nNot found\n");
		for(k = 0; k < dict_size; k++)
		{	
			min_distance[k] = edit_distance(word, dict[k], 0);
		}
		result_min_distance = minimum_distance(dict_size, min_distance);


		printf("\n---> |%s| (words compared when searching: %d)\n", old_version, total);
		printf("-1 - type correction\n");
		printf(" 0 - leave word as is (do not fix spelling)\n");
		printf("     Minimum distance: %d (computed edit distance: %d)\n", result_min_distance, dict_size);
		printf("     Words that give minimum distance:\n");
		
		for(k = 0; k < dict_size; k++)
		{
			compare = edit_distance(word, dict[k], 0);
			if(compare == result_min_distance)
			{
				save_min_words[track] = (char*) malloc((strlen(dict[k]) + 1) * sizeof(char));
				strcpy(save_min_words[track], dict[k]);
				track++;	
			}
		}
		count = track;
		
		PrintWordMin(count, save_min_words);

		User_Choice(old_version, count, save_min_words, fo);
		
		int i;
		for(i = 0; i < count; i++)
		{
			free(save_min_words[i]);
		}
	}
	else
	{	
		printf("\n---> |%s| (words compared when searching: %d)\n", old_version, total);
		printf("       -OK\n\n");
		fprintf(fo, "%s ", old_version);
	}
	
}

/*void SortDict(int size, char* dict[size])
{
	int i, j;
	char* temp = (char*) malloc(100 * sizeof(char));
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size - i - 1; j++)
		{
			if(strcmp(dict[j], dict[j + 1]) > 0)
			{
				strcpy(temp, dict[j]);
				strcpy(dict[j], dict[j + 1]);
				strcpy(dict[j + 1], temp);
			}
		}
	}
	free(temp);	
}*/

static int comparator(const void* str1, const void* str2)
{
	if(strcmp(*(const char**)str1, *(const char**)str2) >= 0)
	{
		return 1;
	}
	else return 0;
}

void ToLower(char* word)
{
	int i;
	for(i = 0; i < strlen(word); i++)
	{
		if(word[i] >= 65 && word[i] <= 90)
		{
			word[i] = word[i] + 32;
		}
	}
}

void spell_check(char * testname, char * dictname, int printOn)
{
	
	int i = 0, dict_size;

	char output[20] = "";
	strcpy(output, "out_");
	strcat(output, testname);
	
	FILE* fp = fopen(dictname, "r");
	FILE* fo;
	
	fo = fopen(output, "w");
	
	if(fo == NULL)
	{
		return;
	}
	
	printf("Corrected output filename: %s\n", output);
	
	if(fp == NULL)
	{
		printf("Could not open file %s. Exit.\n\n", dictname);
		return;
	}

	
	printf("\nLoading the dictionary filename: %s\n", dictname);
	fscanf(fp, "%d\n", &dict_size);
	
	char* line[dict_size];
	
	while( i < dict_size )
	{	
		line[i] = (char*) malloc(20 * sizeof(char));
		fgets(line[i], 100, fp);
		line[i][strlen(line[i]) - 1] = '\0';
		i++;
	}
	fclose(fp);

	printf("\nDictionary has size: %d\n", dict_size);
	if(printOn == 1)
	{
		printf("\nOriginal dictionary:\n");

		int t;
		for(t = 0; t < dict_size; t++)
		{
			printf("%d. %s\n", t, line[t]);
		}
	
		printf("\nSorted dictionary (alphabetical order):\n");
		qsort(line, dict_size, sizeof(const char*), comparator);
		for(t = 0; t < dict_size; t++)
		{
			printf("%d. %s\n", t, line[t]);
		}
	}
	else if(printOn == 0)
	{
		qsort(line, dict_size, sizeof(const char*), comparator);
	}
	else
	{
		printf("\nCannot find the mode\n");
	}
	
	char* ext[100];
	int p = 0, final;
	FILE* sample = fopen(testname, "r");
	
	if(sample == NULL)
	{
		return;
	}

	char* sentence = (char*) malloc(200 * sizeof(char));
	fgets(sentence, 200, sample);
	char* word = strtok(sentence, " ,.!?");
	
	char* old_version[100];
	while(word != NULL)
	{	
		old_version[p] = (char*) malloc((strlen(word) + 1) * sizeof(char));
		strcpy(old_version[p], word);
		ToLower(word);
		ext[p] = word;
		word = strtok(NULL, " ,.!?");
		p = p + 1;
	}
	
	final = p;

	int index = 0;
	while(index < final)
	{
		SearchWord(ext[index], dict_size, line, printOn, old_version[index], fo);
		index++;
	}

	free(sentence);
	
	for(i = 0; i < dict_size; i++)
	{
		free(line[i]);
	}
	for(i = 0; i < final; i++)
	{
		free(old_version[i]);
	}
	
	
	fclose(fo);	
	fclose(sample);
}
