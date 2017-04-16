int aim,b,e;
vector<int> date;
while(b<e){
	if(date[b+(e-b)/2] <= aim)
		e=b+(b-e)/2;
	else
		b=b+(b-e)/2;
}

		
