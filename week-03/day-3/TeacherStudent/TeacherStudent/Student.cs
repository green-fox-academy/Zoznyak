using System;
using System.Collections.Generic;
using System.Text;

namespace TeacherStudent
{
    public class Student
    {
        public string name;

        public Student(string name)
        {
            this.name = name;
        }

        public static void Learn()
        {
            Console.WriteLine("Learning...");
        }

        internal static void Question(Teacher teacher)
        {
            Console.WriteLine("Student asks " + teacher.name);
            Teacher.Answer();
        }

    }
}
