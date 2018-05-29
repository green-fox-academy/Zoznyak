using System;
using System.Collections.Generic;
using System.Text;

namespace GreenFox
{
    class Person
    {
        private string name;
        private int age;
        private string gender;

        public Person(string name, int age, string gender)
        {
            this.name = name;
            this.age = age;
            this.gender = gender;
        }

        public Person()
        {
            this.name = "Jane Doe";
            this.age = 30;
            this.gender = "female";
        }

        public virtual string Introduce()
        {
            return String.Format("Hi, I am {0}, a {1} years old {2}", name, age, gender);
        }

        public virtual string GetGoal()
        {
            return String.Format("My goal is: Live for the moment");
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                this.name = value;
            }           
        }

        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                this.age = value;
            }
        }

        public string Gender
        {
            get
            {
                return gender;
            }
            set
            {
                this.gender = value;
            }
        }
    }
}
