using System;

namespace MileToKmConverter
{
    class Program
    {
        static void Main(string[] args)
        {
            int distanceInKm = 0;
            double distanceInMile = 0.0;

            Console.WriteLine("Type the distance in KM!");
            distanceInKm = int.Parse(Console.ReadLine());
            Console.WriteLine("The distance in Mile: " + distanceInKm * 0.621371192);
            
            Console.ReadLine();
        }
    }
}
