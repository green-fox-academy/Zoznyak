using System;
using System.Collections.Generic;
using System.Text;

namespace TeacherStudent
{
    class Teacher
    {
        string name;

        public Teacher(string name)
        {
            this.name = name;
        }

        public static void Answer()
        {
            Console.WriteLine("Teacher's answer");
        }

        public static void Teach()
        {
            Console.WriteLine("Teaching...");
            Student.Learn();
        }
    }
}
