#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define KEYBOARD_ROW_SIZE 10
int from_one_row(char* word, const char keyboard_row[KEYBOARD_ROW_SIZE]);
char** findWords(char** words, int wordsSize, int* returnSize);
static const char keyoard_layout[3][KEYBOARD_ROW_SIZE]={{'q','w','e','r','t','y','u','i','o','p'},{'a','s','d','f','g','h','j','k','l','\0'},
    {'z','x','c','v','b','n','m','\0'}
};
char** findWords(char** words, int wordsSize, int* returnSize) {
    char** words_from_one_row=malloc(sizeof(char*)*0);
    for(int i=0;i<wordsSize;++i){
		bool found=false;
        for(int row=0;row<3;++row){
            int letter_index_in_row=0;
            while(letter_index_in_row<KEYBOARD_ROW_SIZE&&keyoard_layout[row][letter_index_in_row]!='\0'){
                if((words[i][0]==keyoard_layout[row][letter_index_in_row]) || (words[i][0]==(keyoard_layout[row][letter_index_in_row]-32))){
                    int word_size=from_one_row(words[i],keyoard_layout[row]);
                    if(word_size>0){
                        words_from_one_row=(char **)realloc(words_from_one_row,sizeof(char*)*((*returnSize)+1));
                        words_from_one_row[(*returnSize)]=(char*) malloc(sizeof(char)*word_size);
                        strncpy(words_from_one_row[(*returnSize)++],words[i],word_size);
						found=true;
                        break;
                    }
                }
                letter_index_in_row++;
            }
			if(found){
                break;
            }
        }
    }
    return words_from_one_row;
}

int from_one_row(char* word, const char keyboard_row[KEYBOARD_ROW_SIZE]){
    if((*word)=='\0'){
        return -1;
    }
    int word_index=0;
    while(word[word_index]!='\0'){
        int keyboard_row_index=0;
        bool found=false;
        while(keyboard_row_index<KEYBOARD_ROW_SIZE&&keyboard_row[keyboard_row_index]!=0){
            if(word[word_index]==keyboard_row[keyboard_row_index] || 
            word[word_index]==(keyboard_row[keyboard_row_index]-32)){
				//printf("word[%d] is %c, matches %c in keyboard [%d]\n",word_index,word[word_index],keyboard_row[keyboard_row_index],keyboard_row_index);
                found=true;
                break;
            }
			keyboard_row_index++;
        }
        if(!found){
            return -1;
        }
		word_index++;
    }
	/*printf("[");
	int i=0;
	while(i<word_index){
		printf("%c",word[i]);
		i++;
	}
	printf("]\n");
    printf("index is %d\n",word_index);*/
	
    return word_index;
}

int main(void){
	char * test[10]={"asdfghjkla","qwertyuiopq","zxcvbnzzm"};
	int returnSize=0;
	char** words;
	words=findWords(test,3,&returnSize);
	for(int i=0;i<returnSize;++i){
		int j=0;
		printf("[");
		while(words[i][j]!='\0'){
			printf("%c",words[i][j]);
			j++;
		}
		printf("],");
	}
	printf("\n");
    return 0;
}