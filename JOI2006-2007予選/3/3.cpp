#include <stdio.h>

int main()
{
		char c;
		c=getchar();
		while('A'<=c && c<='Z'){
				if(c=='A'){
						c='X';
				}else if(c=='B'){
						c='Y';
				}else if(c=='C'){
						c='Z';
				}else{
						c-=3;
				}
				printf("%c",c);
				c=getchar();
		}
		return 0;
}
