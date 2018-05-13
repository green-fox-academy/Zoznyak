using System;

namespace DrawChessTable
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfLines;

            Console.WriteLine("How many lines you want?");
            numberOfLines = int.Parse(Console.ReadLine());
            for (int i = 0; i < numberOfLines; i++)
            {
                if (i % 2 == 0)
                {
                    Console.WriteLine(" % % % %");
                }
                else
                {
                    Console.WriteLine("% % % % ");
                }
            }
            Console.ReadLine();
        }
    }
}
