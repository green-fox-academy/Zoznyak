using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments
{
    public abstract class Instrument
    {
        private string name;

        protected Instrument(string name)
        {
            this.name = name;
        }

        public abstract void Play();
    }
}
