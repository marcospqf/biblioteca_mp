int z[N];
void zfunc(string &s)
{
    int l=0,r=0;
    z[0]=s.size();
    for(int i=1;i<s.size();i++){
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(z[i]+i<s.size() and s[i+z[i]]==s[z[i]]) z[i]++;
        if(r<i+z[i]-1) l=i,r=i+z[i]-1;
    }
}
