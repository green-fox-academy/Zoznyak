using System;

namespace Power
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(PowerIt(3, 1));
            Console.ReadLine();
        }

        private static int PowerIt(int number, int power)
        {
            if (power == 0)
            {
                return 1;
            }

            else if (power == 1)
            {
                return number;
            }

            return number * PowerIt(number, power - 1);
        }
    }
}
