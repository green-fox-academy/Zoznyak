using System;
using System.Collections.Generic;
using System.Text;

namespace Zoo
{
    public class Bird : Animal
    {
        public string Name
        {
            get
            {
                return this.name;
            }
        }

        public int Age
        {
            get
            {
                return this.age;
            }
        }

        public Bird(string name, int age, string gender, int weight) : base(name, age, gender, weight)
        {
            this.name = name;
        }

        public override string WantChild()
        {
            return "egg";
        }

        public override string Greet()
        {
            return String.Format("Hi, I am {0}", name);
        }
    }
}
