#include <stdio.h>
void string_recorder(char* s){
    int record[36] = {0};
    int i = 0,max=0;
    while(s[i] != '\0'){
        if(s[i] >= '0' && s[i] <= '9'){
            record[s[i]-'0']++;
            if(max < record[s[i]-'0']){
                max = record[s[i]-'0'];
            }
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            record[s[i]-'a'+10]++;
            if(max < record[s[i]-'a'+10]){
                max = record[s[i]-'a'+10];
            }
        }else{
            printf("<invalid input string>\n");
        }
        i++;
    }
    while(max > 0){
        for(i = 0;i<36;i++){
            if(record[i] > 0){
                if(i > 9){
                    printf("%c",'a'+i-10);
                }else{
                    printf("%c",'0'+i);
                }
                record[i]--;
            }
        }
    }
    printf("\n");
}
int main(){
    char s[100];
    while(scanf("%s",s) != EOF){
        string_recorder(s);
    }
    return 0;
}