using System;

namespace Sharpie
{
    class Program
    {
        static void Main(string[] args)
        {
            Sharpie sharpieOne = new Sharpie("Red", 5f);
            for (int i = 0; i < 5; i++)
            {
                sharpieOne.Use();
            }
            Console.WriteLine($"{sharpieOne.inkAmount}% of the ink available");
            Console.ReadLine();
        }
    }
}
