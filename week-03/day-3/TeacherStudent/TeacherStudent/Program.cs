using System;

namespace TeacherStudent
{
    class Program
    {
        static void Main(string[] args)
        {
            Student studentOne = new Student("Moricka");
            Student studentTwo = new Student("Jozsika");
            Teacher teacher = new Teacher("Juli neni");

            Teacher.Teach();
            Student.Question();

            Console.ReadLine();
        }
    }
}
