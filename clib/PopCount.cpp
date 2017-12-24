int popCount(int _mask)
{
    int r=0;
    for(int i=0;i<31;i++)
        if(_mask & (1<<i))
            r++;
    return r;
}

int popCount(long long _mask)
{
    int r=0;
    for(long long i=0;i<62;i++)
        if(_mask & ((long long)(1)<<i))
            r++;
    return r;
}

