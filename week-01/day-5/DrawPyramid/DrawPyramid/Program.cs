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
            spaces = number-2;

            for (int i = 1; i <= number; i++)
            {
                for (int j = spaces; j >= 0; j--)
                {
                    Console.Write(" ");
                }
                for (int k = 1; k <= (i*2)-1; k++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
                spaces -= 1;
            }
            Console.ReadLine();
        }
    }
}
