using System;

namespace DrawDiamond
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;
            int spaces;

            do
            {
                Console.WriteLine("Give me a number!");
                number = int.Parse(Console.ReadLine());
            } while (number%2 == 0);

            Console.WriteLine();
            spaces = number / 2;

            for (int i = 1; i <= number; i++)
            {              
                if (i>=(number/2)+1)
                {
                    for (int j = 0; j <= i - ((number / 2) + 1); j++)
                    {
                        Console.Write(" ");
                    }
                    for (int k = ((number * 2) + 1) - (i * 2); k >=1; k--)
                    {
                        Console.Write("*");
                    }
                }
                else 
                {
                    for (int j = spaces; j >= 0; j--)
                    {
                        Console.Write(" ");
                    }
                    for (int k = 1; k <= (i * 2) - 1; k++)
                    {
                        Console.Write("*");
                    }
                }
                Console.WriteLine();
                spaces -= 1;
            }
            Console.ReadLine();
        }
    }
}
