using System;

namespace ReversedArray
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                int[] abc = { 1, 2, 3, 4, 5 };
                ReverseIt2(abc).CopyTo(abc, 0);
                for (int i = 0; i < abc.Length; i++)
                {
                    Console.Write(abc[i] + " ");
                }
                Console.ReadLine();
            }
        }
        public static int[] ReverseIt2(int[] arrayOne)
        { 
            {
                int[] help = new int[arrayOne.Length];
                for (int i = 0; i < arrayOne.Length; i++)
                {
                    help[(arrayOne.Length - i - 1)] = arrayOne[i];
                }
                return help;
            }
        }

    }
}
