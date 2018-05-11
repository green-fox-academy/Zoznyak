using System;

namespace DrawTriangle
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;

            Console.WriteLine("Give me a number!");
            number = int.Parse(Console.ReadLine());
            Console.WriteLine();

            for (int i = 1; i <= number; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}
