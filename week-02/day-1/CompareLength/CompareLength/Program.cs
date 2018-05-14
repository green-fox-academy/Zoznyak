using System;

namespace CompareLength
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] p1 = { 1, 2, 3 };
            int[] p2 = { 4, 5, 7, 8 };
            if (p2.Length>p1.Length)
            {
                Console.WriteLine("'p2' has more elements");
            }
            Console.ReadLine();
        }
    }
}
