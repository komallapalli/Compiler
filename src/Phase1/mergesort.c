int func main()
{
  int list arr[100001],list temp[100001];
  int i,j,k,n,size,l1,h1,l2,h2;

  scanin(n);

  for(i=0;i<=n-1;i++)
  {
    scanin(list arr[i]);
  }

  for(size=1; size <= n-1; size++)
  {
    l1=0;
    k=0;
    size = size*2;
    while( l1+size < n)
    {
      h1=l1+size-1;
      l2=h1+1;
      h2=l2+size-1;

      if(h2>=n)
      {
        h2=n-1;
      }
      i=l1;
      j=l2;

      while(i<=h1)
      {
        while(j <= h2)
        {
          if(list arr[i] <= list arr[j])
          {
            list temp[k]= list arr[i];
            k = k+1;
            i = i+1;
          }
          else
          {
            list temp[k]= list arr[j];
            k = k+1;
            j = j+1;
          }
        }
      }

      while(i<=h1)
      {
        list temp[k]= list arr[i];
        k = k+1;
        i = i+1;
      }
      while(j<=h2)
      {
        list temp[k]=list arr[j];
        k = k+1;
        j = j+1;
      }
      l1=h2+1;
    }
    for(i=l1; k<=n-1; i++)
    {
      list temp[k]=list arr[i];
      k = k+1;
    }

    for(i=0;i<=n-1;i++)
    {
      list arr[i]=list temp[i];
    }

    for( i = 0 ; i<=n-1 ; i++)
    {
      printout(list arr[i]);
    }
  }
  for( i = 0 ; i<=n-1 ; i++)
  {
    printout(list arr[i]);
  }

	return 0;
}
