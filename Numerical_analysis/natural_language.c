#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//確率的自然言語生成プログラムです
int main(void){

    FILE *fp1,*fp2;
    char ch;
    //テキストファイルを読み込んでスペースと半角アルファベットのみを別のファイルに書くプログラム
    if((fp1 = fopen("English_text.txt","r"))== NULL){
        printf("ファイルが開けませんでした");
        exit(1);
    }
    if((fp2 = fopen("out_text.txt","w"))==NULL){
        printf("ファイルを開けませんでした");
        exit(1);
    }

    while(feof(fp1)==0){
        ch = fgetc(fp1);
        if(isalpha(ch)!= 0 || ch == ' '){
            if(fputc(ch,fp2) == EOF){
            printf("ファイルに書き込めませんでした");
            exit(1);
            }
            //putchar(ch);
        }else{
            ch=' ';
            fputc(ch,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    return 0;

}