using System;

namespace AnimalsAndLegs
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfChickens;
            int numberOfPigs;
            int numberOfLegs;

            Console.WriteLine("How many chickens do you have on your farm?");
            numberOfChickens = int.Parse(Console.ReadLine());
            Console.WriteLine("How many pigs do you have on your farm?");
            numberOfPigs = int.Parse(Console.ReadLine());
            numberOfLegs = (numberOfChickens * 2) + (numberOfPigs * 4);
            Console.WriteLine("There are {0} legs on your farm!", numberOfLegs);

            Console.ReadLine();
        }
    }
}
