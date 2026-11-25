//Richard Dawkins "Methinks it is a Weasel" experiment, written in C
//2026/11/25


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char a = 'a'; 
char m[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";   
char key[29] = "METHINKS IT IS LIKE A WEASEL";
char parent [29] = "";
char children [100][29];
int childscore [100];




int mutations = 0;
int mutationsT = 0;
int passes = 0;
int score = 0;
int bestscore = 0;

int main(){
    parent[28] = '\0';
    //initial random string
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 28; i++){
        int r = rand() % 27;
        parent[i] = m[r];
    }

    

    printf("Parent string: %s\n", parent);

    while(strcmp(parent, key) != 0){
        for(int j = 0; j < 100; j++){
            strcpy(children[j], parent);
        }
        int mutations = 0;
        //mutating
        for(int j = 0; j < 100; j++){
            for(int i = 0; i < 28; i++){
                int chance = rand() % 100;
                int r = rand() % 27;
                if(chance > 90){
                    children[j][i] = m[r];
                    mutations ++;
                    mutationsT ++;
                }
            }
            if(j % 2 == 0){
                printf("%s\n", children[j]);
            }
            
        }
        //scoring
        for(int j = 0; j < 100; j++){
            childscore[j] = 0;
            for(int i = 0; i < 28; i++){
                if(key[i] == children[j][i]){
                    childscore[j] ++;
                }
            }
        }        
        //sorting
        for(int j = 0; j < 100; j++){
                printf("%d\n", childscore[j]);
                score = childscore[j];
                if(score > bestscore){
                    bestscore = score;
                    strcpy(parent, children[j]);
            }
        }
        bestscore = 0;
        passes ++;                 
        printf("New Parent: %s\n", parent);
    }       

    printf("There were: %d", mutationsT);
    printf(" mutations in total\n");
    printf("There were: %d", passes);
    printf(" generations in total");

}


//notes
//you need to use the format ("%c", char) in order to print. through \n after %c in order to print new line
//in a similar veing, a string need the formate ("%s", string). \n still works
//strings need "string", char needs 'char'
