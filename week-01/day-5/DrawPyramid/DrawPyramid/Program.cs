using System;

namespace DrawPyramid
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;
            int spaces;

            Console.WriteLine("Give me a number!");
            number = int.Parse(Console.ReadLine());
            Console.WriteLine();
            spaces = (number / 2)-1;

            for (int i = 1; i <= number; i+=2)
            {
                for (int j = spaces; j >= 0; j--)
                {
                    Console.Write(" ");
                }
                for (int k = 1; k <= i; k++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
                Console.WriteLine();
                spaces -= 1;
            }
            Console.ReadLine();
        }
    }
}
