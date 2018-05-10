using System;

namespace Cuboid
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 0;
            double b = 0;
            double c = 0;


            Console.WriteLine("Type the length of the first side: ");
            a = double.Parse(Console.ReadLine());
            Console.WriteLine("Type the length of the second side: ");
            b = double.Parse(Console.ReadLine());
            Console.WriteLine("Type the length of the third side: ");
            c = double.Parse(Console.ReadLine());

            Console.WriteLine("Surface Area: " + 2 * ((a * b) + (a * c) + (b * c)));
            Console.WriteLine("Volume: " + a * b * c);


            Console.ReadLine();
        }
    }
}
