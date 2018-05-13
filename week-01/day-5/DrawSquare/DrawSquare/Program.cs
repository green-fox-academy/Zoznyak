using System;

namespace DrawSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;

            Console.WriteLine("Enter a number: ");
            number = int.Parse(Console.ReadLine());
            Console.WriteLine("%%%%%");
            for (int i = 0; i < number-2; i++)
            {
                Console.WriteLine("%   %");
            }
            Console.WriteLine("%%%%%");
            Console.ReadLine();
        }
    }
}
