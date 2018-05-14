using System;

namespace SumElements
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] r = { 54, 23, 66, 12 };
            Console.WriteLine(Sum(r));
            Console.ReadLine();
        }
        public static int Sum(int [] arrayOne)
        {
            return arrayOne[1] + arrayOne[2];
        }
    }
}
