using System;
using System.Collections.Generic;
using System.Text;

namespace Garden
{
    class Flower : Plant
    {
        public Flower(string color) : base(color)
        {
            this.color = color;
        }

        public override void Water(int amount)
        {
            levelOfWater += amount * 0.75;
        }

        public override string LevelOfWater()
        {
            if (levelOfWater >= 5)
            {
                return String.Format("The {0} flower does not need water!", color);
            }
            else return String.Format("The {0} flower needs water!", color);
        }

    }
}
