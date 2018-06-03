using System;
using System.Collections.Generic;
using System.Text;

namespace TeacherStudent
{
    public class Teacher
    {
        public string name;
        public Teacher(string name)
        {
            this.name = name;
        }

        public static void Answer()
        {
            Console.WriteLine("Teacher's answer");
        }

        public static void Teach(Teacher teacher, Student student)
        {
            Console.WriteLine(teacher.name + " is teaching " + student.name + ".");
        }
    }
}
