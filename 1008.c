#include <stdio.h>
#include <string.h>
/*
玛雅两种历法的转换
Haab: 一年365天，分为19个月，按顺序为:pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu, uayet
前18个月每个月20天，用数字0-19 表示,第19个月只有5天，用数字0-4表示

Tzolkin: 一年分为13个阶段（1-13），一个阶段20天（imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau），
一年的天数用数字和单词组合的方式表示 比如1 imix,2 ik,3 akbal...一直循环 

将Haab历法转为Tzolkin
NumberOfTheDay. Month Year=>Number NameOfTheDay Year
*/
int main(){
	char H[19][10]={"pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
	char T[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	int n;
	scanf("%d",&n);
	int i,j;
	printf("%d\n", n);
	int day, year;
	char month[10];
	for(i = 0;i<n;i++){
		scanf("%d. %s %d", &day, month, &year);
		for(j = 0;j<19;j++){
			if(strcmp(H[j],month) == 0){
				break;
			}
		}
		int num = day + j * 20 + year * 365;
		int yeay_t = num/260;
		int day_t = num%260;
		printf("%d %s %d\n", (day_t%13+1),T[day_t%20],yeay_t);
	}
	return 0;
}