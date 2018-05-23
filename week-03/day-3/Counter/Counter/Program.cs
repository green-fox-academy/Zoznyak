using System;

namespace Counter
{
    class Program
    {
        static void Main(string[] args)
        {
            Counter counterOne = new Counter(5);
            counterOne.Add();
            Console.WriteLine($"Current value is: {counterOne.Get()}");
            counterOne.Add(7);
            Console.WriteLine($"Current value is: {counterOne.Get()}");
            counterOne.Reset();
            Console.WriteLine($"Current value is: {counterOne.Get()}");
            Console.ReadLine();
        }
    }
}
