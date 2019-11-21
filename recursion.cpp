int findways(int numDice, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    else if (sum < 0 || numDice == 0)
    {
        return 0;
    }
    
    return findways(numDice - 1, sum - 1)
         + findways(numDice - 1, sum - 2)
         + findways(numDice - 1, sum - 3)
         + findways(numDice - 1, sum - 4)
         + findways(numDice - 1, sum - 5)
         + findways(numDice - 1, sum - 6);
}