#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50
/*
根据字符串的乱序值排序，比如CAA 的乱序值是2 因为C比他后面的两个字母大；
CBAA 的乱序值是3+2=5
*/
void quick_sort(char ** input, int * value, int begin, int end, int len);
int main(){
	int n,m;
	scanf("%d%d",&n, &m);
	int i,j,k;
	char **input;
	int * unsortedness;
	input = (char **)malloc(sizeof(char *) * m);
	unsortedness = (int *)malloc(sizeof(int) * m);
	for (i = 0; i < m; ++i)
	{
		input[i] = (char *)malloc(sizeof(char) * n);
		scanf("%s",input[i]);
		// 求乱序值
		unsortedness[i] = 0;
		for(j = 0;j<n-1;j++){
			for(k = j+1;k<n;k++){
				if(input[i][j] > input[i][k]){
					unsortedness[i]++;
				}
			}
		}
	}
	quick_sort(input, unsortedness, 0,m-1,n);
	for(i = 0;i<m;i++){
		printf("%s\n",input[i] );
	}
	return 0;
}
void quick_sort(char ** input, int * value, int begin, int end, int len){
	int i, j, tmpValue;
	char p[len];
//	int mid;
	if(end <= begin){
		return;
	}
	i = begin;
	j = end;
	strcpy(p, input[begin]);
	tmpValue = value[begin];
	while(i < j){
	//	mid = (i+j)/2;
		while(value[j] > tmpValue && i < j) j--;
		if(value[j] == tmpValue && i < j) j--;//若将这行和上一行合并，即使用>=作为判断条件，那么对于每行都相同的输入，将会是最坏的复杂度
		if(i < j){
			strcpy(input[i], input[j]);
			value[i] = value[j];
		}
		while(value[i] < tmpValue && i < j) i++;
		if(value[i] == tmpValue && i < j) i++;
		if(i < j){
			strcpy(input[j], input[i]);
			value[j] = value[i];
		}
	}
	strcpy(input[i], p);
	value[i] = tmpValue;
	quick_sort(input, value, begin, i-1, len);
	quick_sort(input, value, i+1, end, len);
}