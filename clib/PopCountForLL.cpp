int popCount(LL _mask)
{
	int r=0;
	for(LL i=0;i<62;i++)
		if(_mask & (LL(1)<<i))
			r++;
	return r;
}

