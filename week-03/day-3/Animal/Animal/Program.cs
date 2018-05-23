using System;

namespace Animal
{
    class Program
    {
        static void Main(string[] args)
        {
            Animal tiger = new Animal(50, 50);
            Animal dog = new Animal(50, 50);
            tiger.Drink();
            dog.Play();
            dog.Eat();
            dog.Drink();
            dog.Play();
            dog.Play();
            dog.Play();
            dog.Play();
            Console.WriteLine("Hunger level of your Tiger: {0}", tiger.thirst);
            Console.WriteLine($"Thirst level of yor dog: {dog.thirst}");
            Console.WriteLine(dog.hunger);
            Console.ReadLine();
        }
    }
}
