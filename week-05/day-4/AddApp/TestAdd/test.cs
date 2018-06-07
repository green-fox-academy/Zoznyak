using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AddApp
{
    [TestFixture]
    public class test
    {
        [TestCase]
        public void Add()
        {
            Matek matek = new Matek();
            Assert.AreEqual(6, matek.AddNumbers(2, 4));
        }
    }
}
