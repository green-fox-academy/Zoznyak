using System;
using System.Collections.Generic;
using System.Text;

namespace Garden
{
    class Plant
    {
        protected string color;
        protected static double levelOfWater = 0;

        public Plant(string color)
        {
            this.color = color;
            //this.levelOfWater = 0;
        }

        public virtual void Water(int amount)
        {
            levelOfWater += amount * 1;
        }

        public virtual string LevelOfWater()
        {
            if (levelOfWater >= 5)
            {
                return String.Format("The {0} flower does not need water!", color);
            }
            else return String.Format("The {0} flower needs water!", color);
        }
    }
}
