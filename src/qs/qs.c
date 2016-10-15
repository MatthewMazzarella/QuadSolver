#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*Read in inputs while there are inputs in file given in command line input */

int takeInputs();
int runFile();
char *remove_newline(char *s);


int main(int argc, char * argv[]){
	
	if(argc < 2){
		takeInputs();
		//printf("No filename included\n");
		//return -1;
	}
	else{
		char * f = argv[1];
		if(runFile(f) == 0) return 0;
		else return -1;
	}

	
	return 0;
}

int takeInputs(){
	char s[100];
	char * p = s;
	float a;
	float b;
	float c;


	for(;;){

		printf("Enter your floats for the quadratic equation: \n");
		printf("A: ");
		fgets(s, sizeof(s), stdin);
		p = remove_newline(p);
		a = atof(p);

		printf("B: ");
		fgets(s, sizeof(s), stdin);
		p = remove_newline(p);
		b = atof(p);

		printf("C: ");
		fgets(s, sizeof(s), stdin);
		p = remove_newline(p);
		c = atof(p);

		printf("found %5.5f %5.5f %5.5f \n",a,b,c);
		//call qsolv

	}
	return 0;
}



int runFile(char * fname){


	FILE * fp;

	if(!(fp = fopen(fname,"r"))) return -1;
	
	char * token;
	float a, b, c;
	char readin[256];

	while(fgets(readin,sizeof(readin),fp)){
		token = strtok(readin," ");
		a = atof(token);
		token = strtok(NULL," ");
		b = atof(token);
		token = strtok(NULL," ");
		c = atof(token);

		printf("found %5.5f %5.5f %5.5f \n",a,b,c);

		//call qsolv
	}

	fclose(fp);

	return 0;

}

char *remove_newline(char *s)
{
    int len = strlen(s);

    if (len > 0 && s[len-1] == '\n')  // if there's a newline
        s[len-1] = '\0';          // truncate the string

    return s;
}