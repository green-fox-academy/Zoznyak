using System;

namespace Bunny2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(BunnyEars(5));
            Console.ReadLine();
        }

        private static int BunnyEars(int numbersOfBunnies)
        {
            if (numbersOfBunnies == 1)
            {
                return 3;
            }

            else if (numbersOfBunnies % 2 == 0)
            {
                return 2 + BunnyEars(numbersOfBunnies - 1);
            }

            else
            {
                return 3 + BunnyEars(numbersOfBunnies - 1);
            }
        }
    }
}
