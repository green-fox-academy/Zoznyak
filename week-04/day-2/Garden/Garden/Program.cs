using System;
using System.Collections.Generic;

namespace Garden
{
    class Program
    {
        static void Main(string[] args)
        {
            var plantsInTheGarden = new List<Plant>();

            Flower yellow = new Flower("yellow");
            plantsInTheGarden.Add(yellow);
            Flower blue = new Flower("blue");
            plantsInTheGarden.Add(blue);
            Tree purple = new Tree("purple");
            plantsInTheGarden.Add(purple);
            Tree orange = new Tree("orange");
            plantsInTheGarden.Add(orange);

            foreach (var plant in plantsInTheGarden)
            {
                Console.WriteLine(plant.LevelOfWater());
            }
            WaterPlants(40, plantsInTheGarden);
            Console.WriteLine();
            foreach (var plant in plantsInTheGarden)
            {
                Console.WriteLine(plant.LevelOfWater());
            }
            WaterPlants(70, plantsInTheGarden);
            Console.WriteLine();
            foreach (var plant in plantsInTheGarden)
            {
                Console.WriteLine(plant.LevelOfWater());
            }
            Console.ReadLine();
        }

        public static void WaterPlants(int amountOfWater, List<Plant> plantsInTheGarden)
        {
            int waterForEach = amountOfWater / plantsInTheGarden.Count;
            foreach (var plant in plantsInTheGarden)
            {
                plant.Water(waterForEach);
            }
        }

    }
}
