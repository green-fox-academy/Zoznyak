using System;

namespace PostIt
{
    class Program
    {
        static void Main(string[] args)
        {
            PostIt postItOne = new PostIt("Orange", "Idea 1", "Blue");
            PostIt postItTwo = new PostIt("Pink", "Awsome", "Black");
            PostIt postItThree = new PostIt("Green", "Superb!", "Green");

            Console.WriteLine(postItOne.backgroundColor);
            Console.WriteLine(postItThree.textOnIt);

            Console.ReadLine();
        }
    }
}
