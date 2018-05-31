using System;

namespace Garden
{
    class Tree : Plant
    {
        public Tree(string color) : base(color)
        {
            this.color = color;
        }

        public override void Water(int amount)
        {
            levelOfWater += amount * 0.4;
        }

        public override string LevelOfWater()
        {
            if (levelOfWater >= 10)
            {
                needWater = false;
                return String.Format("The {0} tree does not need water! {1}", color, levelOfWater);
            }
            else
                needWater = true;
            return String.Format("The {0} tree needs water! {1}", color, levelOfWater);
        }
    }
}
