using System;

namespace Doubling
{
    class Program
    {
        static void Main(string[] args)
        {
            int baseNum = 123;

            Console.WriteLine(Doubling(baseNum));
            Console.ReadLine();
        }

        static int Doubling(int num1)
        {
            return num1 * 2;
        }
    }
}
