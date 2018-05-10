using System;

namespace HelloUser
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = " ";

            Console.WriteLine("Type your name please!");
            name = Console.ReadLine();
            Console.WriteLine("Hello {0}!", name);

            Console.ReadLine();
        }
    }
}
