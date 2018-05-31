using NUnit.Framework;
using System;

namespace Apples
{
    [TestFixture]
    public class Class1
    {
        [TestCase]
        public void WorksOrNot()
        {
            var appleOne = new Apple("red apple");
            string testText = "red apple";

            Assert.AreEqual(appleOne.GetName, testText);
        }
    }
}
