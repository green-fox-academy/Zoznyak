using System;

namespace SumAllElements
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ai = { 3, 4, 5, 6, 7 };
            Console.WriteLine(SumAll(ai));
            Console.ReadLine();
        }
        public static int SumAll(int[] arrayOne)
        {
            int sum=0;
            for (int i = 0; i < arrayOne.Length; i++)
            {
                sum += arrayOne[i];
            }
            return sum;
        }
    }
}
