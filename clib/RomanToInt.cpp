char roman[]="IVXLCDM";
int  digit[]={1,5,10,50,100,500,1000};
int romanToInt(string s){
	int n=s.size();
	vector<int> vi(n);
	for(int i=0;i<n;i++){
		s[i]=toupper(s[i]);
		for(int j=0;j<7;j++)
			if(roman[j]==s[i])
				vi[i]=digit[j];
	}
	int r=0;
	for(int i=0;i<n;i++){
		if(i+1<n&&vi[i]<vi[i+1])
			r-=vi[i];
		else
			r+=vi[i];
	}
	return r;
}

