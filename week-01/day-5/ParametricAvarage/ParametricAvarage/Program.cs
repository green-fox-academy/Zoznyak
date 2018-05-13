using System;

namespace ParametricAvarage
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfNumbers;
            int number = 0;
            int sum = 0;
            double avarage;

            Console.WriteLine("How many numbers you want to type in?");
            numberOfNumbers = int.Parse(Console.ReadLine());
            for (int i = 0; i < numberOfNumbers; i++)
            {
                Console.WriteLine("Enter a number!");
                number = int.Parse(Console.ReadLine());
                sum += number;
            }
            avarage = (double)sum / numberOfNumbers;
            Console.WriteLine("Sum: " + sum);
            Console.WriteLine("Avarage: " + avarage);
            Console.ReadLine();
        }
    }
}
