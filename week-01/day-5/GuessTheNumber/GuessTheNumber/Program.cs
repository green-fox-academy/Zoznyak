using System;

namespace GuessTheNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int number = rnd.Next(1, 101);
            int guess = 0;

            while (guess != number) 
            {
                Console.WriteLine("What is your guess?");
                guess = int.Parse(Console.ReadLine());
                if (number > guess)
                {
                    Console.WriteLine("The number is higher!");
                }
                if (number < guess)
                {
                    Console.WriteLine("The number is less!");
                }
            }
            Console.WriteLine("Good job!");
            Console.ReadLine();
        }
    }
}
