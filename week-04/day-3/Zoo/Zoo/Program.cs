using System;

namespace Zoo
{
    class Program
    {
        static void Main(string[] args)
        {
            var bird = new Bird("Parrot", 3, "male", 1);

            Console.WriteLine("Who want a baby?");
            Console.WriteLine(bird.Greet()); 
            Console.WriteLine("{0} is {1} years old and wants a child from an {2}.", bird.Name, bird.Age, bird.WantChild());
            Console.ReadLine();
        }
    }
}
