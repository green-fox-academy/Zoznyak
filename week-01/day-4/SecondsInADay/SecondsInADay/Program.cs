using System;

namespace SecondsInADay
{
    class Program
    {
        static void Main(string[] args)
        {
            int currentHours = 23;
            int currentMinutes = 59;
            int currentSeconds = 50;
            int aDayInSecond = 86400;

            Console.WriteLine(("Remaining secods from the day: ") + (aDayInSecond - (currentHours * 60 * 60) - (currentMinutes * 60) - currentSeconds));


            Console.ReadLine();
        }
    }
}
