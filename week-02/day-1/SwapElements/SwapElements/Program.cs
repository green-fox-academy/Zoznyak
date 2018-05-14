using System;

namespace SwapElements
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] abc = { "first", "second", "third" };
            SwapIt(abc);
            for (int i = 0; i < abc.Length; i++)
            {
                Console.WriteLine(abc[i]);
            }
            Console.ReadLine();
        }
        public static string[] SwapIt(string[] arrayOne)
        {
            string help;
            help = arrayOne[0];
            arrayOne[0] = arrayOne[2];
            arrayOne[2] = help;
            return arrayOne;
        }
    }
}
