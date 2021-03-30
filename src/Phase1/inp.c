int pow(int base,int exp)
{
  int prod;
  prod = 1;
  for(i = 1; i <= exp; i++)
  {
    prod = prod * base;
  }
  return prod;
}

int func main()
{
  int i,k,n,sum;
  scanin(n);
  scanin(k);
  sum=0;
  for(i=1; i <= 3 ; i++)
  {
    sum = sum + pow(int i,int j);
  }
  printout(sum);
}
