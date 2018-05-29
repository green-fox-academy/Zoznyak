using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Person janeDoe = new Person();
            Console.WriteLine(janeDoe.Introduce());
            Console.WriteLine(janeDoe.GetGoal());
            Console.ReadLine();
        }
    }
}
