bool isPrime(int num)
{
  bool check;
  int i;
  check = true;
  for(i=1;i<=num;i++)
  {
    if(num%i == 0)
    {
      check = false;
    }
  }
  return check;
}

int func main()
{
  int sum,i,n;
  sum = 0;
  scanin(n);
  for(i=0; i <= n; i++)
  {
    if(a < 2)
    {
      sum = sum + i;
    }
  }
  printout(sum);
  return 0;
}
