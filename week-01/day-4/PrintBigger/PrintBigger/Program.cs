using System;

namespace PrintBigger
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;
            int b;

            Console.WriteLine("First number: ");
            a = int.Parse(Console.ReadLine());
            Console.WriteLine("Second number: ");
            b = int.Parse(Console.ReadLine());

            if (a>b)
            {
                Console.WriteLine(a + " is the bigger!");
            }
            else if (b>a)
            {
                Console.WriteLine(b + " is the bigger!");
            }
            else
            {
                Console.WriteLine("The two numbers are equal!");
            }
            Console.ReadLine();
        }
    }
}
