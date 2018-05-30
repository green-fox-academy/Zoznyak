using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments
{
    public abstract class Instrument
    {
        protected string name;

        public abstract void Play();

        public abstract string Sound();
    }
}
