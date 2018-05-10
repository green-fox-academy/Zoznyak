using System;

namespace VariableMutation
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 3;
            int b = 100;
            int c = 44;
            int d = 125;
            int e = 8;
            int f1 = 123;
            int f2 = 345;
            int g1 = 350;
            int g2 = 200;
            long h = 1357988018575474;
            int i1 = 10;
            int i2 = 3;
            int j = 1521;
            string k = "Apple";

            Console.WriteLine(a += 10);
            Console.WriteLine(b -= 7);
            Console.WriteLine(c *= 2);
            Console.WriteLine(d /= 5);
            Console.WriteLine(e *= e);
            Console.WriteLine(f1 > f2);
            Console.WriteLine(g2 * 2 > g1);
            Console.WriteLine(h % 11 == 0);
            Console.WriteLine((Math.Sqrt(i2) < i1) && (i1 < Math.Pow(i2, 2)));
            Console.WriteLine((j % 3 == 0) || (j % 5 == 0));
            Console.WriteLine(k = k + k + k + k);
            Console.ReadLine();
        }
    }
}
