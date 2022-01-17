
/* Name: Gia Dao, Student ID: 1001747062 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_COURSES 50

struct node
{
	char* name;
	char* color;
	char* pred;
	int course_num;
};


bool DFS_visit(int final, int position, struct node vertex[final], int array[final][final], struct node result[final], int* ptr)
{
	int j;
	strcpy(vertex[position].color, "grey");
	for(j = 0; j < final; j++)
	{
		if(array[position][j] == 1)
		{
			if(strcmp(vertex[j].color, "white") == 0)
			{
				vertex[j].pred = (char*) calloc(strlen(vertex[position].name) + 1, sizeof(char));
				strncpy(vertex[j].pred, vertex[position].name, strlen(vertex[position].name));
				DFS_visit(final, j, vertex, array, result, ptr);  
			}
			if(strcmp(vertex[j].color, "grey") == 0)
			{
				return false;
			}
		}
	}
	strcpy(vertex[position].color, "black");
	
	if(strcmp(vertex[position].color, "black") == 0 && *ptr < final)
	{
		result[*ptr].name = (char*) calloc(strlen(vertex[position].name) + 1, sizeof(char));
		strncpy(result[*ptr].name, vertex[position].name, strlen(vertex[position].name));
		result[*ptr].course_num = vertex[position].course_num;
		*ptr = *ptr + 1;
	}
}

void ReadNode(int final, char* course[final], int array[final][final])
{
	int i, p;
	bool check = true;
	int count = 0;
	int* ptr = &count;
	struct node vertex[final];
	struct node result[final];
	for (i = 0; i < final; i++)
	{
		vertex[i].name = (char*) calloc(strlen(course[i]) + 1, sizeof(char));
		vertex[i].color = (char*) calloc(6, sizeof(char));
		vertex[i].pred = NULL;
		strncpy(vertex[i].name, course[i], strlen(course[i]));
		strcpy(vertex[i].color, "white");
		vertex[i].course_num = i;
	}

	for(i = 0; i < final; i++)
	{
		if(strcmp(vertex[i].color, "white") == 0)
		{
			check = DFS_visit(final, i, vertex, array, result, ptr);
		}
	}
	if(check == false) 
	{
		printf("There was at least one cycle. There is no possible ordering of the courses.\n\n");	
	}
	else
	{
		printf("Order in which to take courses:\n");
		for(i = final - 1; i >= 0; i--)
		{
			p = final - i;
			printf("%d. - %s (corresponding to graph vertex %d)\n", p, result[i].name, result[i].course_num);
		}
	}
	
	for(i = 0; i < final; i++)
	{
		free(vertex[i].name);
		free(vertex[i].color);
		if(vertex[i].pred != NULL)
		{
			free(vertex[i].pred);
		}
		free(result[i].name);
	}
	
}

void PrintArray(int final, int array[final][final])
{
	int i, j;
	printf("%4c", '|');
	for(i = 0; i < final; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	printf("%s", "----");	
	for(i = 0; i < final; i++)
	{
		printf("---");	
	}
	printf("\n");

	for(i = 0; i < final; i++)
	{
		printf("%3d%c", i, '|');
		for(j = 0; j < final; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}


void GraphMatrix(int final, char* course[final], char* prequisite[final])
{
	int i, j;
	char* ret;
	int graph_matrix[final][final];

	for(i = 0; i < final; i++)
	{
		for(j = 0; j < final; j++)
		{
			graph_matrix[i][j] = 0;	
		}
	}

	for(i = 0; i < final; i++)
	{
		char* temp = (char*) calloc(strlen(course[i]) + 1, sizeof(char));
		strncpy(temp, course[i], strlen(course[i]));
		for(j = 0; j < final; j++)
		{
			ret = strstr(prequisite[j], temp);
			if(ret)
			{
				graph_matrix[i][j] = 1;
			}
		}
		free(temp);
	}
	PrintArray(final, graph_matrix);
	printf("\n");
	ReadNode(final, course, graph_matrix);
}

int check(char* line)
{
	int i;
	for(i = 0; i < strlen(line); i++)
	{
		if(line[i] == ' ')
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	int t = 0;

	char filename[30];
	printf("\nThis program will read, from a file, a list of courses and their prerequisites and will print the list in which to take courses.\n");
	printf("Enter filename: ");
	scanf("%s", filename);

	FILE* fp;
	fp = fopen(filename, "r");
	if(fp == NULL)
	{
		printf("Could not open file %s. Exit.\n\n", filename);
		printf("Failed to read from file. Program will terminate.\n\n");
		exit(EXIT_FAILURE);
	}

	int final = 0;
	char line[100][1000];
	
	while( fgets(line[t], 1000, fp) )
	{	
		line[t][strlen(line[t]) - 1] = '\0';
		t++;
	}
	final = t;
	
	fclose(fp);
	
	int i;
	
	
	printf("\nNumber of vertices in built graph: N = %d\n", final);
	
	char* course[final];
	char* prequisite[final];
	int count;
	for(i = 0; i < final; i++)
	{	
		count = 0;
		course[i] = (char*) calloc(30, sizeof(char));
		if(check(line[i]) == 1)
		{
			strncpy(course[i], line[i], strlen(line[i]));
			prequisite[i] = (char*) calloc(1, sizeof(char));
		}
		else
		{
			int length = strlen(line[i]);
			char* word = strtok(line[i], " ");
			prequisite[i] = (char*) calloc(length - strlen(word), sizeof(char));
			strncpy(course[i], word, strlen(word));
			while(count < 1)
			{
				word = strtok(NULL, "\n");
				strncpy(prequisite[i], word, strlen(word));
				count++;
			}
		}
	}
	
	printf("Vertex - coursename correspondence\n");
	for(i = 0; i < final; i++)
	{
		printf("%d - %s\n", i, course[i]);
	}
	printf("\n");
	
	
	printf("\n");

	printf("Adjacency matrix:\n");
	GraphMatrix(final, course, prequisite);
	printf("\n\n");
	
	for(i = 0; i < final; i++)
	{
		if(course[i] != NULL && prequisite[i] != NULL)
		{
			free(course[i]);
			free(prequisite[i]);
		}
		else
		{
			free(course[i]);
		}
	}
	return 0;
}
