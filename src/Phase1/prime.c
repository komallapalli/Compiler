int func main()
{
  int n, i, flag;
  flag = 0;
  scanin(n);
  for(i = 2; i <= n/2; i++)
  {
      if(n%i == 0)
      {
          flag = 1;
      }
  }
  if (n == 1)
  {
    printout("1 is neither a prime nor a composite number.");
  }
  else
  {
      if (flag == 0)
      {
        printout("%d is a prime number.");
        printout(n);
      }
      else
      {
        printout("%d is not a prime number.");
        printout(n);
      }
      return 0;
  }
}
