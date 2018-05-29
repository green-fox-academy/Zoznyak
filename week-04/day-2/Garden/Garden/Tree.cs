﻿using System;
using System.Collections.Generic;
using System.Text;

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
                return String.Format("The {0} tree does not need water!", color);
            }
            else return String.Format("The {0} tree needs water!", color);
        }
    }
}
