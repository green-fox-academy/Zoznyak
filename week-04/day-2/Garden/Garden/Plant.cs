using System;
using System.Collections.Generic;
using System.Text;

namespace Garden
{
    public abstract class Plant
    {
        protected string color;
        protected double levelOfWater;
        protected bool needWater;

        public Plant(string color)
        {
            this.color = color;
            levelOfWater = 0;
            needWater = true;
        }

        public bool NeedWater
        {
            get
                {
                return needWater;
                }
        }

        public abstract void Water(int amount);

        public abstract string LevelOfWater();
    }
}
