using System;
using System.Collections.Generic;
using System.Text;

namespace BlogPost
{
    class BlogPost
    {
        public string authorName;
        public string title;
        public string text;
        public string publicationDate;

        public BlogPost(string authorName, string title, string text, string publicationDate)
        {
            this.authorName = authorName;
            this.title = title;
            this.text = text;
            this.publicationDate = publicationDate;
        }
    }
}
