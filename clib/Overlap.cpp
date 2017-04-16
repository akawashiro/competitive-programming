 //return overlap between [a1,a2] and [b1,b2]
int overlap(int a1,int a2,int b1,int b2)
{
	if(a1<=b1 && b1<=a2 && a2<=b2)
		return a2-b1+1;
	else if(a1<=b1 && b2<=a2)
		return b2-b1+1;
	else if(b1<=a1 && a2<=b2)
		return a2-a1+1;
	else if(b1<=a1 && a1<=b2 && b2<=a2)
		return b2-a1+1;
	else
		return 0;
}
