using System;

namespace SumDigit
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(SumDigits(45));
            Console.ReadLine();
        }

        private static int SumDigits(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            else
            {
                return n % 10 + SumDigits(n / 10);
            }
        }
    }
}
