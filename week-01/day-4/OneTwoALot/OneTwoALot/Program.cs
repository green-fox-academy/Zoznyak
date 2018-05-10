using System;

namespace OneTwoALot
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;

            Console.WriteLine("Type in a number!");
            number = int.Parse(Console.ReadLine());
            if (number <= 0)
            {
                Console.WriteLine("Not enough");
            }
            else if (number == 1)
            {
                Console.WriteLine("One");
            }
            else if (number == 2)
            {
                Console.WriteLine("Two");
            }
            else
            {
                Console.WriteLine("A lot");
            }
            Console.ReadLine();
        }
    }
}
