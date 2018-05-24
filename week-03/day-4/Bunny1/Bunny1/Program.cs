using System;

namespace Bunny1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(BunnyEars(3));
            Console.ReadLine();
        }

        public static int BunnyEars(int numberOfBunnys)
        {
            if (numberOfBunnys == 1)
            {
                return 2;
            }

            else
            {
                return 2 + BunnyEars(numberOfBunnys-1);
            }
        }
    }
}
