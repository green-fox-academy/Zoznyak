using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            var mark = new Person("Mark", 46, "male");
            var jane = new Person();
            var john = new Student("John Doe", 20, "male", "BME");
            var student = new Student();
            var gandhi = new Mentor("Gandhi", 148, "male", "senior");
            var mentor = new Mentor();
            var elon = new Sponsor("Elon Musk", 46, "male", "SpaceX");
            var sponsor = new Sponsor();

            Console.WriteLine(mark.Introduce());
            Console.WriteLine(john.SkippedDays);
            Console.WriteLine(gandhi.Introduce());
            Console.WriteLine(elon.Introduce());
            elon.Hire();
            Console.WriteLine(elon.Introduce());


            Console.ReadLine();
        }
    }
}
