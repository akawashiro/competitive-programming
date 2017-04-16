int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<31;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

