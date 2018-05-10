using System;

namespace DefineBasicInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = "Kasza Zoltan";
            int age = 31;
            double height = 1.77;
            bool married = false;

            Console.WriteLine("Hello, my name is: {0}, I am {1}, my height is {2}.",name,age,height);
            if (married == true)
            {
                Console.WriteLine("I am married!");
            }
            else
            { 
                Console.WriteLine("I am not married!");
            }
            Console.ReadLine();
        }
    }
}
