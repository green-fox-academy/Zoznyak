using System;

namespace PartyIndicator
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfGirls;
            int numberOfBoys;

            Console.WriteLine("How many girls will attend to the party?");
            numberOfGirls =  int.Parse(Console.ReadLine());
            Console.WriteLine("How many boys will attend to the party?");
            numberOfBoys = int.Parse(Console.ReadLine());

            if ((numberOfGirls == numberOfBoys) && ((numberOfBoys + numberOfGirls) > 20))
            {
                Console.WriteLine("The party is excellent!");
            }
            else if ((numberOfGirls != numberOfBoys) && ((numberOfBoys + numberOfGirls) > 20))
            {
                Console.WriteLine("Quite cool party!");
            }
            else if ((numberOfBoys + numberOfGirls) <= 20)
            {
                Console.WriteLine("Avarage party!");
            }
            else if ((numberOfGirls) <= 0)
            {
                Console.WriteLine("Sausage party!");
            }
            Console.ReadLine();
        }
    }
}
