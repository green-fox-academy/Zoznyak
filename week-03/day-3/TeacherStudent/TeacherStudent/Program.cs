using System;

namespace TeacherStudent
{
    class Program
    {
        static void Main(string[] args)
        {
            Student studentOne = new Student("Moricka");
            Student studentTwo = new Student("Jozsika");
            Teacher teacherOne = new Teacher("Juli neni");
            Teacher teacherTwo = new Teacher("Zsuzsi neni");
            Teacher.Teach(teacherOne, studentOne);
            Console.ReadLine();
        }
    }
}
