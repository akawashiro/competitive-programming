#include <stack>
#include <stdio.h>

using namespace std;

char grid[500+10][500+10];
int  a[500+10][500+10];

int main()
{
	while(1){
		int h,w;
		scanf("%d%d",&h,&w);
		if(!h && !w)
			break;
		for(int i=0;i<h;i++){
			scanf("%s",grid[i]);
			/*printf("%s\n",grid[i]);
			fflush(stdout);*/
		}
		int ans=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++)
				if(i==0)
					if(grid[i][j]=='.')
						a[i][j]=1;
					else
						a[i][j]=0;
				else
					if(grid[i][j]=='.')
						a[i][j]=a[i-1][j]+1;
					else
						a[i][j]=0;
			stack<int> height,x;
			for(int j=0;j<w;j++){
				int b=j;
				while(!height.empty() && a[i][j]<=height.top()){
					int S=height.top()*(j-x.top());
					/*if(ans<S)
						
						printf("i=%d j=%d x=%d h=%d\n",i,j,x.top(),height.top());*/
					b=x.top();
					ans=max(ans,S);
					height.pop();
					x.pop();
				}
				height.push(a[i][j]);
				x.push(b);
			}
			while(!height.empty()){
				int S=height.top()*(w-x.top());
				/*if(ans<S)
					printf("i=%d x=%d h=%d\n",i,x.top(),height.top());*/
				ans=max(ans,S);
				height.pop();
				x.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



