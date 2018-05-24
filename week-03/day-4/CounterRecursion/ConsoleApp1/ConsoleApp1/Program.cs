using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            RecursiveCounter(8);
            Console.ReadLine();
        }

        public static void RecursiveCounter(int n)
        {
            if (n >= 0)
            {
                Console.WriteLine(n);
                RecursiveCounter(n-1);
            }            
        }
    }
}
