using System;
using System.Collections.Generic;
using System.Text;

namespace PostIt
{
    class PostIt
    {
        public string backgroundColor;
        public string textOnIt;
        public string textColor;

        public PostIt(string backgroundColor, string textOnIt, string textColor)
        {
            this.backgroundColor = backgroundColor;
            this.textOnIt = textOnIt;
            this.textColor = textColor;
        }
    }
}
