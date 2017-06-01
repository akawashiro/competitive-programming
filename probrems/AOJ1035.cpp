#include <iostream>

using namespace std;

int wall[100+10];

int main()
{
	while(1){
		int w,q;
		cin>>w>>q;
		if(w==0 && q==0)
			break;
		for(int i=0;i<w;i++)
			wall[i]=-1;
		for(int i=0;i<q;i++){
			/*for(int j=0;j<w;j++)
				cout<<wall[j]<<" ";
			cout<<endl;*/
			char c;
			cin>>c;
			if(c=='s'){
				int id,l;
				cin>>id>>l;
				int s,suc=0;
				for(s=0;s+l<=w;s++){
					int j;
					for(j=s;j<s+l;j++)
						if(wall[j]!=-1)
							break;
					if(j==s+l){
						for(j=s;j<s+l;j++)
							wall[j]=id;
						suc=1;
						break;
					}
				}
				if(suc)
					cout<<s<<endl;
				else
					cout<<"impossible"<<endl;
			}else{
				int id;
				cin>>id;
				for(int j=0;j<w;j++)
					if(wall[j]==id)
						wall[j]=-1;
			}
		}
		cout<<"END"<<endl;
	}
		return 0;
}

