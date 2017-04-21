#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int from_one_row(char* word, const char* keyboard_row);
char** findWords(char** words, int wordsSize, int* returnSize);
static const char keyoard_layout[10][10]={{'q','w','e','r','t','y','u','i','o','p'},{'a','s','d','f','g','h','j','k','l'},
    {'z','x','c','v','b','n','m'}
};
char** findWords(char** words, int wordsSize, int* returnSize) {
    char** words_from_one_row=malloc(sizeof(char*)*0);
    for(int i=0;i<wordsSize;++i){
        for(int row=0;row<3;++row){
            int letter_index_in_row=0;
            while(keyoard_layout[row][letter_index_in_row]!='\0'){
                if(words[i][0]==keyoard_layout[row][letter_index_in_row] || 
                words[i][0]==(keyoard_layout[row][letter_index_in_row]+32)){
                    int word_size=from_one_row(words[i],keyoard_layout[row]);
                    if(word_size>0){
                        words_from_one_row=(char **)realloc(words_from_one_row,sizeof(char*)*((*returnSize)+1));
                        words_from_one_row[(*returnSize)]=(char*) malloc(sizeof(char)*word_size);
                        strncpy(words_from_one_row[(*returnSize)++],words[i],word_size);
                    }
                }
                printf("row is %d\n",row);
                printf("letter_index_in_row is %d\n",letter_index_in_row);
                letter_index_in_row++;
            }
        }
    }
    return words_from_one_row;
}

int from_one_row(char* word, const char* keyboard_row){
    if((*word)=='\0'){
        return -1;
    }
    int word_index=0;
    while(word[word_index++]!='\0'){
        int keyboard_row_index=0;
        bool found=false;
        while(keyboard_row[keyboard_row_index++]!=0){
            if(word[word_index]==keyboard_row[keyboard_row_index] || 
            word[word_index]==(keyboard_row[keyboard_row_index]+32)){
                found=true;
                break;
            }
        }
        if(!found){
            return -1;
        }
    }
    printf("index is %d\n",word_index);
    return ++word_index;
}

int main(void){
	char ** test={"Hello","Alaska","Dad","Peace"};
	int returnSize=0;
	char** words;
	words=findWords(test,4,&returnSize);
	for(int i=0;i<returnSize;++i){
		int j=0;
		printf("[");
		while(words[i][j]!='\0'){
			printf("%s",words[i][j]);
			j++;
		}
		printf("],");
	}
	printf("\n");
    return 0;
}