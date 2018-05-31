using System;

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
                needWater = false;
                return String.Format("The {0} flower does not need water! {1}", color, levelOfWater);
            }
            else
                needWater = true;
            return String.Format("The {0} flower needs water! {1}", color, levelOfWater);
        }
    }
}
