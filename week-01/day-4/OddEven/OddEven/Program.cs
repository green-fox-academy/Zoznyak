using System;

namespace OddEven
{
    class Program
    {
        static void Main(string[] args)
        {
            float number = 0.0f;

            Console.WriteLine("Type in a number!");
            number = float.Parse(Console.ReadLine());

            if (number % 2.0f == 0)
            {
                Console.WriteLine("{0} is even", number);
            }
            else
	        {
                Console.WriteLine("{0} is odd", number);
            }
            Console.ReadLine();
        }
    }
}
