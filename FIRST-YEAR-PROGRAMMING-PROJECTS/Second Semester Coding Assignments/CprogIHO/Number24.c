#include <stdio.h>

void printstringreverse(char *str){
	
	if(*str != '\0'){
		printstringreverse(str + 1);
		printf("%c", *str);
	}	
}

int main(){
	
	char *str = "w3resource";
	
	printstringreverse(str);
	
	return 0;
}
