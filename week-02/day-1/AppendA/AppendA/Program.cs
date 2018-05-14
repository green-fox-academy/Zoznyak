using System;

namespace AppendA
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] animals = { "kuty", "macsk", "cic" };
            ChangeIt(animals);
            for (int i = 0; i < animals.Length; i++)
            {
                Console.WriteLine(animals[i]);
            }           
            Console.ReadLine();
        }
        public static string[] ChangeIt(string[] arrayOne)
        {
            for (int i = 0; i < arrayOne.Length; i++)
            {
                arrayOne[i] += "a";
            }
            return arrayOne;
        }
    }
}
