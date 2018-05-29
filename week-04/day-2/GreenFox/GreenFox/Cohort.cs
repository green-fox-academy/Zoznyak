using System;
using System.Collections.Generic;
using System.Text;

namespace GreenFox
{
    class Cohort
    {
        private string name;
        List<Student> students = new List<Student>();
        List<Mentor> mentors = new List<Mentor>();

        public Cohort(string name)
        {
            this.name = name;
        }

        public void AddStudent(Student name)
        {
            students.Add(name);
        }

        public void AddMentor(Mentor name)
        {
            mentors.Add(name);
        }

        public string Info()
        {
            return String.Format("The {0} chorot has {1} students and {2} mentors.",  name, students.Count, mentors.Count); 
        }

    }
}
