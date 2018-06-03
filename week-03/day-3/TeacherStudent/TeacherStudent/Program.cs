using System;

namespace TeacherStudent
{
    class Program
    {
        static void Main(string[] args)
        {
            Student moricka = new Student("Moricka");
            Student jozsika = new Student("Jozsika");
            Teacher juliNeni = new Teacher("Juli neni");
            Teacher zsuzsiNeni = new Teacher("Zsuzsi neni");
            Teacher.Teach(juliNeni, moricka);
            Console.ReadLine();
        }
    }
}
