using System;

namespace AvarageOfInput
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;
            int b;
            int c;
            int d;
            int e;

            Console.WriteLine("First number: ");
            a = int.Parse(Console.ReadLine());
            Console.WriteLine("Second number: ");
            b = int.Parse(Console.ReadLine());
            Console.WriteLine("Third number: ");
            c = int.Parse(Console.ReadLine());
            Console.WriteLine("Fourth number: ");
            d = int.Parse(Console.ReadLine());
            Console.WriteLine("Fifth number: ");
            e = int.Parse(Console.ReadLine());

            Console.WriteLine("Sum: " + (a+b+c+d+e));
            Console.WriteLine("Avarge: " + ((a + b + c + d + e) / 5.0));
            
            Console.ReadLine();
        }
    }
}
