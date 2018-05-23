using System;
using System.Collections.Generic;
using System.Text;

namespace Animal
{
    class Animal
    {
        public int hunger;
        public int thirst;

        public Animal(int hunger, int thirst)
        {
            this.hunger = hunger;
            this.thirst = thirst;
        }

        public void Eat()
        {
            this.hunger--;
        }

        public void Drink()
        {
            this.thirst--;
        }

        public void Play()
        {
            this.hunger++;
            this.thirst++;
        }
    }
}
