using System;

namespace Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;
            Console.WriteLine("Give me a number");
            number = int.Parse(Console.ReadLine());
            Console.WriteLine(Sum(number));
            Console.ReadLine();
        }
        public static int Sum(int num1)
        {
            return (num1 * (num1 + 1)) / 2;
        }
    }
}
