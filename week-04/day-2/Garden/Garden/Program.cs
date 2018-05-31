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
            WaterPlants(40, ThirstyPlants(plantsInTheGarden));
            Console.WriteLine();
            Console.WriteLine("Let's water the plants with 40 liters of water");
            Console.WriteLine();
            foreach (var plant in plantsInTheGarden)
            {
                Console.WriteLine(plant.LevelOfWater());
            }
            WaterPlants(70, ThirstyPlants(plantsInTheGarden));
            Console.WriteLine();
            Console.WriteLine("Let's water the plants with 70 liters of water");
            Console.WriteLine();
            foreach (var plant in plantsInTheGarden)
            {
                Console.WriteLine(plant.LevelOfWater());
            }
            Console.ReadLine();
        }

        public static List<Plant> ThirstyPlants(List<Plant> plantsInTheGarden)
        {
            List<Plant> thirstyPlants = new List<Plant>();
            foreach (var plant in plantsInTheGarden)
            {
                if (plant.NeedWater == true)
                {
                    thirstyPlants.Add(plant);
                }
            }
            return thirstyPlants;
        }

        public static void WaterPlants(int amountOfWater, List<Plant> thirstyPlants)
        {
            int waterForEach = amountOfWater / thirstyPlants.Count;
            foreach (var plant in thirstyPlants)
            {
                plant.Water(waterForEach);
            }
        }
    }
}
